# Predicting sine wave values on Arduino Nano with TensorFlow Lite

This project consists of two major parts:

- Firstly, training a model that predicts values of the $\sin(x)$ function using TensorFlow. Then, using TensorFlow Lite to convert this model and generate a C++ file.
- Then, running the converted model on an **Arduino Nano** board and using the resulting simulated function to control a blinking LED.

All the code can be found inside the **code** folder.

Training and conversion of the neural network model is done in **building_TFLite_mode.ipynb**. Since this is a simple model, it can be run locally or on the cloud using Google Colab.
