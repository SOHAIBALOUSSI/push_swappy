import random

def generate_non_duplicated_numbers(start, end, count):
    if end - start + 1 < count:
        raise ValueError("Count must be less than or equal to the range of numbers.")
    
    # Generate non-duplicated numbers
    numbers = random.sample(range(start, end + 1), count)
    return numbers

start_range = 1
end_range = 500
count = 500  # You can adjust this count as needed

non_duplicated_numbers = generate_non_duplicated_numbers(start_range, end_range, count)
print(non_duplicated_numbers)

