from flask import Flask, request, send_from_directory
import os

app = Flask(__name__)
static_directory = 'static'
flag = "ISC2CTF{Tr@VeR$Ing_THe_d!r3c7ORIEs}"

@app.route('/')
def root():
    return send_from_directory(static_directory, 'index.html')

@app.route('/search')
def search():
    page = request.args.get('page')

    if not page:
        return "Please specify a 'page' parameter to search for a file."

    file_path = os.path.join(static_directory, page)

    if not os.path.isfile(file_path):
        return "File not found."

    with open(file_path, 'r') as f:
        return f.read()

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=8000)
