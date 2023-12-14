FROM python:3.7.13-alpine3.16

COPY flag.txt .

COPY chal /app
WORKDIR /app

RUN pip install flask

CMD ["python", "app.py"]