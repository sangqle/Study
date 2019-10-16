# Set the base image using miniconda 
FROM continuumio/miniconda3:4.3.27

# Set environmental variable(s)
ENV ACCEPT_INTEL_PYTHON_EULA=yes

# Set working directory 
WORKDIR /home/notebooks

# Add requirements file 
ADD requirements.txt /app/

# Installs, clean, and update   
RUN apt-get update \
    && apt-get clean \
    && apt-get update -qqq \
    && apt-get install -y -q g++ \ 
    && conda config --add channels intel \
    && conda install  -y -q intelpython2_full=2018.0.1 python=3 \ 
    && pip install --upgrade pip \ 
    && pip install -r /app/requirements.txt

# Run shell command for notebook on start 
CMD jupyter notebook --port=8888 --no-browser --ip=0.0.0.0 --allow-root