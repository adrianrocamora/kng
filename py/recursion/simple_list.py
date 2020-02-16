# Return a new list that is the result of adding element
# to the head of the input list
def attach_head(element, input_list):
  return [element] + input_list

def sum_list_recursive(input_list):
  if input_list == []:
    return 0
  head = input_list[0]
  smaller_list = input_list[1:]
  return head + sum_list_recursive(smaller_list)

print(sum_list_recursive(list(range(1,101))))
