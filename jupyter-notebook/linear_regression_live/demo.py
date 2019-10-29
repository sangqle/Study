from numpy import *

def gradient_descent_runner(points, starting_b, starting_m, learning_rate, num_interatinos):
  b = starting_b
  m = starting_m

def run():
    points = genfromtext('data.csv', delimiter=',')
    #hyperparameters
    learning_rate = 0.0001
    #y = mx + b
    initial_b = 0
    initial_m = 0
    num_iterations = 1000
    [b, m] = gradient_descent_runner(points, initial_b, initial_m, learning_rate, num_iterations)
    print(b)
    print(m)
if__name__ = '__main__':
    run()