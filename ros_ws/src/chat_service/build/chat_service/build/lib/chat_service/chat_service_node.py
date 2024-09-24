#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from chat_service.srv import Chat
import openai
import os

INSTRUCTIONS = "You are a helpful assistant."

TEMPERATURE = 0.5
MAX_TOKENS = 500
FREQUENCY_PENALTY = 0
PRESENCE_PENALTY = 0.6
MAX_CONTEXT_QUESTIONS = 10

# Set up OpenAI API key
def get_openai_api_key(file_path):
    try:
        with open(file_path, 'r') as file:
            api_key = file.read().strip()
            if not api_key:
                raise ValueError("API key file is empty.")
            return api_key
    except FileNotFoundError:
        raise FileNotFoundError(f"The API key file was not found at: {file_path}")
    except Exception as e:
        raise e

class ChatServiceNode(Node):
    def __init__(self):
        super().__init__('chat_service_node')
        self.srv = self.create_service(Chat, 'chat_service', self.handle_chat)

        self.conversation_history = []

        # Initialize ChatGPT API Key
        api_key_file = os.path.expanduser('~/CHATGPT_KEY')
        try:
            api_key = get_openai_api_key(api_key_file)
            openai.api_key = api_key
            self.get_logger().info('OpenAI API key successfully loaded.')
        except Exception as e:
            self.get_logger().error(f'Failed to load OpenAI API key: {e}')
            # Optionally, shut down the node if the API key is critical
            rclpy.shutdown()

    def handle_chat(self, request, response):
        if not request.message:
            self.get_logger().warn('Received empty message.')
            response.success = False
            response.response = "No message received."
            return response

        try:
            # Initialize messages with system instructions
            messages = [
                {"role": "system", "content": INSTRUCTIONS},
            ]

            # Add previous conversation history
            if self.conversation_history:
                # Each exchange consists of a user message and an assistant response
                num_messages_to_include = MAX_CONTEXT_QUESTIONS * 2
                recent_history = self.conversation_history[-num_messages_to_include:]
                messages.extend(recent_history)

            # Add the new user message
            messages.append({"role": "user", "content": request.message})

            # Get response from ChatGPT
            completion = openai.ChatCompletion.create(
                model="gpt-3.5-turbo",
                messages=messages,
                temperature=TEMPERATURE,
                max_tokens=MAX_TOKENS,
                top_p=1,
                frequency_penalty=FREQUENCY_PENALTY,
                presence_penalty=PRESENCE_PENALTY,
            )

            # Extract the assistant's reply
            assistant_reply = completion.choices[0].message.content.strip()

            # Update the conversation history
            self.conversation_history.append({"role": "user", "content": request.message})
            self.conversation_history.append({"role": "assistant", "content": assistant_reply})

            # Set the response
            response.success = True
            response.response = assistant_reply

            # Log the successful interaction
            self.get_logger().info(f'Chat response: {assistant_reply}')

            return response

        except Exception as e:
            self.get_logger().error(f'Error communicating with ChatGPT API: {e}')
            response.success = False
            response.response = f"Error communicating with ChatGPT API: {str(e)}"
            return response

def main(args=None):
    rclpy.init(args=args)
    node = ChatServiceNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('ChatServiceNode has been shut down.')
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
