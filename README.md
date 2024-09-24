# ROS2 Web Chat Interface

A basic web chat interface for communicating with ROS2 Humble using a custom service and `rosbridge`.

## Project Structure

The project is divided into two main components:

### ros_ws

Contains the ROS2 environment (using ROS Humble) and includes the following packages:

#### Packages

- **chat_service**
  - **Description:** Implements the `chat_service_node` which communicates with the ChatGPT API.
  - **Location:** `ros_ws/src/chat_service`

- **interfaces**
  - **Description:** Defines the `Chat.srv` service used by both the web application and the ROS node for communication.
  - **Location:** `ros_ws/src/interfaces`

### webapp

A standard web application hosted using Flask, accessible on port `8000`.

- **Description:** Provides a user-friendly interface to interact with the ROS2 backend.
- **Location:** `webapp/`
- **Framework:** Flask
- **Port:** `8000`

## Installation

### Prerequisites

- **ROS2 Humble:** Ensure ROS2 Humble is installed and properly set up on your system.
- **Python 3:** Required for running the Flask web application.
- **Dependencies:** Install necessary Python packages (e.g., Flask).
- **GPT-API Key:** Secret chatgpt api key stored in "~/CHATGPT_KEY" file

### Launching ROS Nodes

1. **Build the ROS Workspace:**
   ```bash
   cd ros_ws/
   colcon build
   ```

2. **Source the Setup Script:**
   ```bash
   source install/setup.bash
   ```

3. **Run the Chat Service Node:**
   ```bash
   ros2 run chat_service chat_service_node
   ```

### Starting the Web Application

1. **Launch `rosbridge`:**
   ```bash
   ros2 launch rosbridge_server rosbridge_websocket_launch.xml
   ```

2. **Start the Flask Web Application:**
   ```bash
   cd ../webapp
   python3 app.py
   ```

3. **Access the Web Interface:**
   Open your web browser and navigate to `http://localhost:8000`.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request for any improvements or bug fixes.

---

by [julianleclerc](https://github.com/julianleclerc)*
