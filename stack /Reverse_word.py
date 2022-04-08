from Stack import stack
st = stack()   
A = []
reversed_word = ''  

if __name__ == "__main__":
    stack_size = input("size of word:\n")
    for k in range(0,int(stack_size)):
     st.push(input("ENTER %d º CHARACTER: " %(k+1)))
    
    
    for k in range(0,st.size):
         A.append(st.top.data)
         st.pop()
         reversed_word += A[k] 
    
    print(reversed_word)
