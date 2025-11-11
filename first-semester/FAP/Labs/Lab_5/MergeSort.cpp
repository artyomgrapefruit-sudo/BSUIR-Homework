#include <iostream>

template <typename T>
void swap(T* a, T* b) {
  const T mem = *a;
  *a = *b;
  *b = mem; 
}

template <typename T>
void Merge (T* array, const T* left_array, const T* right_array, size_t size) {
  size_t left_ptr = 0;
  size_t right_ptr = 0;
  size_t array_ptr = 0;
  const size_t middle = size / 2;

  for (;left_ptr < middle && right_ptr < size - middle;) {
    if (left_array[left_ptr] > right_array[right_ptr]) {
      array[array_ptr] = right_array[right_ptr];
      ++right_ptr;
    } else {
      array[array_ptr] = left_array[left_ptr];
      ++left_ptr;
    }
    ++array_ptr;
  }
  while (left_ptr < middle) {
    array[array_ptr] = left_array[left_ptr];
    ++left_ptr;
    ++array_ptr;
  }
  while (right_ptr < size - middle) {
    array[array_ptr] = right_array[right_ptr];
    ++right_ptr;
    ++array_ptr;
  }
}

template <typename T>
T* MergeSort(T* array, size_t left, size_t right) {
  //std::cout << "$" << left << "-" << right << std::endl;
  const size_t size = right - left;
  const size_t middle = (right + left) / 2;
  T* answer = new T[size];

  if(size == 1) {
    *answer = *(array + left);
    return answer;
  }
  if (size == 2) {
    *answer = *(array + left);
    *(answer + 1) = *(array + left + 1);
    if(*answer >= *(answer + 1)) {
      swap(answer, (answer + 1));
    }
    return answer;
  }

  T* left_array = MergeSort(array, left, middle);
  T* right_array = MergeSort(array, middle, right);

  Merge(answer, left_array, right_array, size);
  return answer;
}

template <typename T>
void MergeSort(T* array, const size_t size) {
  const size_t middle = size / 2;

  if(size < 1) {
    throw std::invalid_argument("invalid argument");
    array = nullptr;
    return;
  }
  if(size == 1) {
    return;
  }
  if (size == 2) {
    if(*array >= *(array + 1)) {
      swap(array, (array + 1));
    }
    return;
  }

  T* left_array = MergeSort(array, 0, middle); // [r, l)
  T* right_array = MergeSort(array, middle, size);

  Merge(array, left_array, right_array, size);

  return;
}

int main() {
  size_t n;

  std::cin >> n;

  int64_t* arr = new int64_t[n];

  std::cout << "----------" << std::endl;

  for (size_t curr = 0; curr < n; ++curr) {
    std::cin >> *(arr + curr);
  }

  std::cout << "-----------\n";

  MergeSort(arr, n);

  std::cout << "\n-----------\n";

  std::cout << "\nMS:\n";
  for (size_t curr = 0; curr < n; ++curr) {
    std::cout << *(arr + curr) << " ";
  }
}