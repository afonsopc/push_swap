import os
import sys
import random
import subprocess

if sys.platform == "linux" or sys.platform == "linux2":
    checker = "./checker_linux"
elif sys.platform == "darwin":
    checker = "./checker_Mac"
else:
    raise Exception("Unsupported platform")

if not os.path.exists(checker):
    raise Exception("Checker not found")

os.system(f"chmod +x {checker}")

def get_random_numbers(amount: int):
    numbers = []
    for _ in range(amount):
        while True:
            number = str(random.randint(-10000, 10000))
            if number not in numbers:
                numbers.append(number)
                break
    return numbers

def test(amount: int):
    results = []
    print(f"Testing with {amount} numbers")
    for i in range(1000):
        numbers = get_random_numbers(amount)
        command = f"./push_swap {' '.join(numbers)}"
        push_swap_process = subprocess.run(command, shell=True, capture_output=True, text=True)
        output = push_swap_process.stdout
        push_swap_exit_code = push_swap_process.returncode
        
        checker_command = f"{checker} {' '.join(numbers)}"
        checker_process = subprocess.run(checker_command, input=output, shell=True, capture_output=True, text=True)
        checker_output = checker_process.stdout
        checker_exit_code = checker_process.returncode
        
        results.append({
            "instructions": len(output.split("\n")) - 1,
            "checker": checker_output.strip() == "OK",
            "push_swap_exit_code": push_swap_exit_code,
            "checker_exit_code": checker_exit_code
        })
    
    print("Highest instructions:", max([result["instructions"] for result in results]))
    print("Lowest instructions:", min([result["instructions"] for result in results]))
    print("Average instructions:", sum([result["instructions"] for result in results]) / len(results))
    print("Checker success rate:", sum([result["checker"] for result in results]) / len(results))
    print("Push_swap exit codes:", list(set([result["push_swap_exit_code"] for result in results])))
    print("Checker exit codes:", list(set([result["checker_exit_code"] for result in results])))
    return results

test(1)
print()
test(2)
print()
test(3)
print()
test(4)
print()
test(5)
print()
test(100)
print()
test(500)