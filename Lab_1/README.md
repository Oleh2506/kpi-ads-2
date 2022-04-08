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