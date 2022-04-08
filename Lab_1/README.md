# Лабораторна робота №1

Мета роботи – вивчити основні методи аналізу обчислювальної складності алгоритмів 
внутрішнього сортування і оцінити поріг їх ефективності.

## Аналіз алгоритмів на відповідність властивостям наведено у таблиці:

| Властивість | Сортуваання бульбашкою | Сортування гребінцем |
| ----------- | ----------- | ----------- |
| Стійкість | Стійкий | Стійкий |
| "Природність" поведінки (Adaptability) | Ні | Так |
| Базуються на порівняннях | Так | Так |
| Необхідність в додатковій пам'яті (об'єм) | θ(1) | θ(1) |
| Необхідність в знаннях про структури даних | Масиви | Масиви |

## Псевдокод алгоритму

### Сортування бульбашкою
```
BubbleSort (arr, SIZE):
    for i = 1 to SIZE do 
        for j = 1 to SIZE do
            if arr[j] > arr[j + 1] then
                temp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = temp
            end if
        end for
    end for
end BubbleSort
```

### Сортування гребінцем
```
CombSort (arr, SIZE):
    shrink_factor = 1.2473309
    gap = SIZE
    swapped = True
    while gap > 1 or swapped == True do
        gap = trunc (gap / shrink_factor)
        if gap < 1 then 
            gap = 1
        end if
        swapped = False
        for i = 1 to SIZE – gap + 1 do
            if arr[i] > arr[i + 1] then
                temp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = temp
                swapped = True
            end if
        end for
    end while
end CombSort
```

## Аналіз часової складності

### Сортування бульбашкою
```
(n-1)+(n-1)+⋯+(n-1)=(n-1)∙(n-1)=n^2-2∙n+1=θ(n^2)
Кращий випадок: θ(n^2) 
(n-1)+(n-1)+⋯+(n-1)=(n-1)∙(n-1)=n^2-2∙n+1=Ω(n^2)
Середній випадок: Ω(n^2)
(n-1)+(n-1)+⋯+(n-1)=(n-1)∙(n-1)=n^2-2∙n+1=O(n^2)
Гірший випадок: O(n^2)
```
### Сортування гребінцем
```
Кращий випадок: θ(n∙log⁡(n))
Середній випадок: Ω(n^2)
Гірший випадок: O(n^2)
```

## Програмна реалізація алгоритму

### Вихідний код

#### Сортування бульбашкою
```
void BubbleSort(int* const arr, const int SIZE) {
	for (size_t i{ 0 }; i < SIZE - 1; ++i) {
		for (size_t j{ 0 }; j < SIZE - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}
```
#### Сортування гребінцем
```
void CombSort(int* const arr, const int SIZE) {
	const float shrink_factor{ 1.2473309 };
	int gap{ SIZE };
	bool swapped{ true };

	while (gap > 1 || swapped) {
		gap = static_cast <int> (static_cast <float> (gap) / shrink_factor);
		gap = gap > 1 ? gap : 1;

		swapped = false;
		for (size_t i{ 0 }; i < SIZE - gap; ++i) {
			if (arr[i] > arr[i + gap]) {
				std::swap(arr[i], arr[i + gap]);
				swapped = true;
			}
		}
	}
}
```
### Приклад роботи

#### Сортування бульбашкою

##### Сортування масиву на 100 елементів
![Bubble sort of 100 elements](assets/image3.png)

##### Сортування масиву на 1000 елементів
![Bubble sort of 1000 elements](assets/image4.png)

#### Сортування гребінцем


##### Сортування масиву на 100 елементів
![Comb sort of 100 elements](assets/image5.png)

##### Сортування масиву на 1000 елементів
![Comb sort of 1000 elements](assets/image6.png)
