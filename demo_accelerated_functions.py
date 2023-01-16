import numpy as np
import os
import random
import subprocess

if __name__ == "__main__":
    current_path = os.path.dirname(__file__)
    build_folder_name = "accelerated_functions_build"
    build_path = os.path.join(current_path, build_folder_name)
    if not os.path.exists(build_path):
        os.makedirs(build_path)
    os.chdir(build_path)
    subprocess.check_call(["cmake", ".."])
    subprocess.check_call(["make"])
    os.chdir(current_path)
    import accelerated_functions_build.accelerated_functions as af
    print("************************")
    print("Python code: add() demo:")
    input1 = random.randint(1, 1000)
    input2 = random.randint(1, 1000)
    print("Python code: sending inputs", input1, input2)
    result = af.add(input1, input2)
    print("Python code: received result", result)
    print("************************")
    print("Python code: fill() demo:")
    input3 = np.ndarray(shape=(2,2), dtype=np.float64)
    input3.setflags(write=True)
    input4 = np.float64(random.randint(1, 1000))
    input5 = np.float64(random.randint(1, 1000))
    print("Python code: sending input matrix\n", input3)
    print("Python code: sending input value", input4)
    af.fill(input3, input4)
    print("Python code: matrix modified\n", input3)
