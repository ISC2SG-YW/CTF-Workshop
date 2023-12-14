FROM python:3.7.13-alpine3.16

COPY app .

RUN pip install -r requirements.txt

EXPOSE 1337

ENV PYTHONDONTWRITEBYTECODE=1

CMD ["python3", "app.py"]