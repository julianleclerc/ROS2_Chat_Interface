from flask import Flask, render_template
from flask_cors import CORS
import roslibpy


app = Flask(__name__)
CORS(app)  # enable CORS if ROS Bridge is on a different origin

@app.route('/')
def index():
    return render_template('index.html')

if __name__ == '__main__':
    # run Flask app on port 8000: http://localhost:8000/
    app.run(host='0.0.0.0', port=8000, debug=True)