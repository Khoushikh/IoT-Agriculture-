import json
from urllib.request import urlopen
from datetime import datetime


present= datetime.now()
current_time = present.strftime("%H:%M:%S")
print(present)

f = urlopen("https://api.thingspeak.com/channels/860038/feeds.json?api_key=H7KWMP6Y8XB6OC84&results=10")
json_object = json.load(f)
feeds = json_object["feeds"]
for feed in feeds:
    print(feed["field1"],"\t",feed["field2"])

with open('out.txt', 'a') as output:
    output.write(str(present)+'\n')
    for feed in feeds:
        output.write(feed["field1"] +'\t'+ feed["field2"] +'\n')
       
