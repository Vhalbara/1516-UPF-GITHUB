import io

def multiple():
    id_file = open('exemple.txt','w')
    
    for i in range(20):
        id_file.write(str(i*5))

    id_file.close()
    return
