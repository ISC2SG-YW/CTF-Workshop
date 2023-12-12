FROM ubuntu:latest

RUN apt-get update && apt-get install -y openssh-server

RUN useradd -m -s /bin/bash pwn_me && echo 'pwn_me:lucky13' | chpasswd
RUN useradd -m -s /bin/bash isc2_user && echo 'isc2_user:password123' | chpasswd

COPY flag.txt /home/pwn_me/
COPY message.txt /home/isc2_user/
RUN chown pwn_me:pwn_me /home/pwn_me/flag.txt
RUN chown isc2_user:isc2_user /home/isc2_user/message.txt

RUN chmod o+r /etc/shadow

RUN mkdir /var/run/sshd
RUN sed -i 's/#PermitRootLogin prohibit-password/PermitRootLogin no/' /etc/ssh/sshd_config

EXPOSE 22

CMD ["/usr/sbin/sshd", "-D"]
CMD service ssh start && tail -f /dev/null