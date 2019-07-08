import csv
import folium # это Python-библиотека для визуализации географических данных и информации

m = folium.Map(location = [42, 12.48], zoom_start = 6) # задаем начальные координаты (где будет открываться карта)
with open('Goroda.csv') as f: # мы из файла берем названия и координаты и размещаем их на карте, сохраняя в map
    r = csv.reader(f)
    for z in r:
        folium.Marker([float(z[1]), float(z[2])], tooltip = z[0],icon = folium.Icon(color = 'red')).add_to(m)
with open('Svyazki.csv') as f: #из файла, где хранятся координаты всех городов и вес каждого из путей, мы берем информацию и накладываем все на карту, сохраняя в map
    r = csv.reader(f)
    for z in r:
        folium.PolyLine([[float(z[0]),float(z[1])],
        [float(z[2]),float(z[3])]],
        color = 'red',
        opacity=1, weight=2).add_to(m)
m.save('Answer.html') #наш ответ, открыв который мы получим нашу карту с готовыми путями
