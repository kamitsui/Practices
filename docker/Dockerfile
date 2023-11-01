# Use an official base image (for example, Ubuntu)
FROM ubuntu:latest

# Set environment variables (optional)
ENV MY_VARIABLE=value

# Install dependencies and software
RUN apt-get update && apt-get install -y \
    git \
    vim \
    ssh \
    build-essential \
	curl \
	universal-ctags \
	libreadline-dev \
	tmux \
	xclip \
	valgrind \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Copy files from your local machine to the container (if necessary)
#RUN mkdir -p /root/.ssh
#COPY ssh_config /root/.ssh/config
# Copy your private SSH key (if necessary)
# COPY id_rsa /root/.ssh/id_rsa
# COPY id_rsa.pub /root/.ssh/id_rsa.pub
#RUN chmod 700 /root/.ssh && chmod 600 /root/.ssh/*

# Set the working directory inside the container
WORKDIR /workspace

# Expose ports (optional)
EXPOSE 80

# Run a command when the container starts (optional)
CMD ["bash"]
