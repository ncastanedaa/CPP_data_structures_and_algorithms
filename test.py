#
# AI: Certainly!
# You can create a function that takes in a number and returns its reverse.
# Here’s how you can do it:
#

def reverse_number(num):
  #convert to string
  converted_num=str(num)
  # Reverse the number in string format
  reverse_str = converted_num[::-1]
  #converts it again to integer format
  reverse = int(reverse_str)
  # Return the number

  return reverse

## Example usage:
print(reverse_number(1223)) # Output: 3221
print(reverse_number(987654321)) # Output: 123456789
