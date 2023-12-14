from flask import Flask, request
app = Flask(__name__)

@app.route('/')
def index():
    return open('index.html').read()

@app.route('/file')
def file():
    path = request.args.get('path')
    if path:
        try:
            with open(path, 'r') as f:
                file_contents = f.read()
                return file_contents
        except FileNotFoundError:
            return f"Error: File '{path}' not found"
    else:
        return 'Error: No file path specified'
if __name__ == '__main__':
    app.run(host='0.0.0.0', port=1337)