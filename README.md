# 1C_project
Решение задачи для отбора на кафедру 1С
Задача № 211


Необходимо реализовать эффективный алгоритм поиска по строке в очень большом текстовом файле. Файл загружается один раз, потом происходит большое количество запросов на поиск.

## Описание алгоритма:
По строке, прочитанной из файла построим суффиксальный автомат. Для того чтобы найти очередное слово в тексте, в построенном автомате будем переходить по ребрам(переходам), сответсвующим буквам в слове, пока можем находить такое ребро. Если мы смогли прочесть все слово пройдя по ребрам, то это значит, что это слово есть в тексте, иначе нет. Для того чтобы найти первое вхождение, будем при создании вершины в начале функции AddSym запоминать значение длины уже построенного суффиксального автомата first_pos. Тогда если мы нашли номер вершины v, соответсвующей текущему слову word, то в 1 индексации номер первого вхождения first_pos[v] - word.size() + 2.

Оценка асимптотики: 1) Построение суффиксального автомата за размер текста * работа map на малом константном алфавите для каждой вершины.
2) Время поиска каждого слова в тексте за размер текста * работа map на малом константном алфавите для каждой вершины.
Для хранения переходов выбран map, а не vector, так как в среднем для каждой вершины существует малое количество переходов, поэтому решено не хранить большое количество пустых переходов.

## Документация:

Входные данные: 1) ожидается путь до файла с текстом. 2) количество запросов 3) сами запросы


Пример: в /home/nakazkan/a.txt лежит a.txt с текстом  
"In the town where I was born  
Lived a man who sailed to sea  
And he told us of his life  
In the land of submarines  
So we sailed on to the sun  
'Til we found a sea of green  
And we lived beneath the waves  
In our yellow submarine"

Входные данные:   /home/nakazkan/a.txt   
3  submarine
born 
yesterday  
Выходные данные:  
First occurrence in 103 position  
First occurrence in 26 position  
No occurrences in text  


## Сборка проекта:
Находясь в папке с проектом, пропишите  
mkdir build  
cd build  
cmake ..  
make  
./1C_project

