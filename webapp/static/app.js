document.addEventListener('DOMContentLoaded', function () {
    console.log('JavaScript is loaded and running.');

    const chatlog = document.getElementById('chatlog');
    const messageInput = document.getElementById('messageInput');
    const sendBtn = document.getElementById('sendBtn');

    // initialize ROSLIB
    const ros = new ROSLIB.Ros({
        url: 'ws://localhost:9090' // update to the correct IP
    });

    ros.on('connection', function () {
        console.log('Connected to ROS bridge.');
        appendMessage('System: Connected to ROS bridge.');
    });

    ros.on('error', function (error) {
        console.error('Error connecting to ROS bridge:', error);
        appendMessage('System: Error connecting to ROS bridge.');
    });

    ros.on('close', function () {
        console.log('Connection to ROS bridge closed.');
        appendMessage('System: Connection to ROS bridge closed.');
    });

    // define the service
    const chatService = new ROSLIB.Service({
        ros: ros,
        name: '/chat_service',
        serviceType: 'interfaces/srv/Chat' // correct service type
    });

    // handle send button click
    sendBtn.addEventListener('click', function () {
        console.log('Send button clicked.');
        const message = messageInput.value.trim();
        console.log('Message input:', message);
        if (message === '') {
            console.log('No message to send.');
            appendMessage('System: Please enter a message.');
            return;
        }

        appendMessage('You: ' + message);
        messageInput.value = '';

        const request = new ROSLIB.ServiceRequest({
            message: message
        });

        // call the service
        console.log('Calling ROS service...');
        chatService.callService(request, function (result) {
            console.log('Service response:', result);
            appendMessage('ROS: ' + result.response);
        }, function (error) {
            console.error('Service call failed:', error);
            appendMessage('ROS: Service call failed.');
        });
    });

    // append messages to chatlog
    function appendMessage(message) {
        const p = document.createElement('p');
        p.textContent = message;
        chatlog.appendChild(p);
        chatlog.scrollTop = chatlog.scrollHeight;
        console.log('Appended message:', message);
    }
});
