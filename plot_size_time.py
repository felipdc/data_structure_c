import pandas as pd
import numpy as np
import matplotlib.pyplot as plt


def plot_size_time():

    data = pd.read_csv("/home/metalm/Desktop/version-control/data_c/execute_time.csv")

    size = data['size']

    time = data['time']

    plt.scatter(size, time, s=2)


    plt.xlabel('size of array')

    plt.ylabel('time to sort')

    plt.title('Time to selection sort given array size number')

    plt.show()
    
plot_size_time()
