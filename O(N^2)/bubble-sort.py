
def bubbleSort(array):

	length = len(arr)

	for i in range(length-1):
		swapped = False

		for j in range(length-1-i):
			if arr[j] > arr[j+1]:
				arr[j], arr[j + 1] = arr[j + 1], arr[j]
				swapped = True

		if not swapped:
			break

	return array


arr = [9, 5, 3, 1, 0, 4, 10]
bubbleSort(arr)

print(arr)