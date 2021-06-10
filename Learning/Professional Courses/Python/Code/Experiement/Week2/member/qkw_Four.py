import enchant
import time

from typing_extensions import runtime
d=enchant.Dict("en_US")
def IsWord(word):
    return d.check(word)

def readfile(filename):     #返回一个list
    words=[]
    fin=open(filename,"r")
    for line in fin:
        word=line.strip()
        words.append(word)
    return words

def ShortableWord(word,word_dict,extra_dict,):
    #time.sleep(4)
    #print('IN:' + word)
    length=len(word)
    if(len(word)==1):
        if word=='a' or word=='i':
            extra_dict[word]=1
            return 1
        else:
            extra_dict[word]=0
            return 0
    if word not in word_dict:
        return 0
    else:
        for i in range(length):
            newWord=word[0:i]+word[i+1:length]
            # if (newWord in extra_dict and extra_dict[newWord]==0):
            #     return 0
            if (newWord in extra_dict and extra_dict[newWord]==1) or (newWord in word_dict and word_dict[newWord]==1):
                return 1
        for i in range(length):
            newWord=word[0:i]+word[i+1:length]
            if word not in word_dict:
                continue            
            result=ShortableWord(newWord,word_dict,extra_dict)
            if result==0:
                extra_dict[newWord]=0
                continue
            if result==1:
                extra_dict[newWord]=1
                return 1
        return 0

            
def GoverDict(word_dict):
    file2=open("result1.txt","w")
    #maxlen=0
    extra_dict={}
    ans=[]
    ans_dict={}
    flag=1
    for word in word_dict.keys():
        if ShortableWord(word,word_dict,extra_dict)==1:
            word_dict[word]=1
            ans.append(word)
            ans_dict[word]=len(word)
            # file2.write(word+'\n')
            # if flag==1:
            #     maxWord=word
            #     maxlen=len(word)
            #     flag=0
            # else:
            #     if len(word)>=maxlen:
            #         maxlen=len(word)
            #         maxWord=word
        # print(word+' '+str(word_dict[word])+'\n')
        # file2.write(word+' '+str(word_dict[word])+'\n')
    #print(extra_dict)

    ans_dict=sorted(ans_dict.items(),key=lambda d:d[1],reverse=True)
    maxWords=[]
    #print(ans_dict)
    #file2.write(ans)
    
    for key,value in dict(ans_dict).items():
        if(flag==1):
            maxlength=value
            flag=0
            print(maxlength)
        if(value==maxlength):
            print(value)
            maxWords.append(key)
        file2.write(key+'  '+str(value)+'\n')
    
    return maxWords
            
def CreateOriginDict(word_list):    #返回一个dictionary
    word_dict={x:0 for x in word_list}
    return word_dict

def main():
    begintime=time.time()
    print("BeginTime: ",begintime)
    filename="words.txt"
    word_list=readfile(filename)
    word_dict=CreateOriginDict(word_list)
    maxWord=GoverDict(word_dict)
    endtime=time.time()
    print("EndTime: ",endtime)
    runtime=endtime-begintime
    print("程序耗时: "+str(runtime))
    print(maxWord)
    
    #print(word_dict)
    
main()