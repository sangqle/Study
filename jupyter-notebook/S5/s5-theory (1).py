#!/usr/bin/env python
# coding: utf-8

# In[23]:


import numpy as np
import matplotlib.pyplot as plt


# In[24]:


X = np.array([[0, 0, 1, 1],[0, 1, 0, 1]])
Y = np.array([0, 0, 0, 1])


# In[25]:


X


# In[26]:


X = X.T


# In[30]:


X


# In[27]:


colorMap = np.array(['red', 'green'])


# In[28]:


plt.axis([0, 1.2, 0, 1.2])


# In[32]:


plt.scatter(X[:,0], X[:,1], c=colorMap[Y], s= 150)
plt.xlabel("Gia tri X1")
plt.ylabel("Gia tri X2")
plt.show()


# In[17]:


X[:, 0]


# In[18]:


X


# # cai dat day thuat

# In[15]:


import random
import numpy as np

X = np.array([[0, 0, 1, 1],[0, 1, 0, 1]])
Y = np.array([0, 0, 0, 1])
X = X.T

def my_perceptron(X, y, eta, lanlap):
    n = len(X[0,])
    m = len(X[:,0])
    print("m = ", m, "va n =", n)
    w0 = random.random()
    w = np.random.random()
    #w0= -0.2
    #w = (0.5, 0.5)
    print(" w0 =", w0)
    print(" w =", w)
    for t in range(0, lanlap):
        print("lanlap ----", t)
        for i in range(0, m):
            gx = w0 + sum(X[i,]*w)
            print("gx = ", gx)
            if(gx > 0):
                output = 1
            else:
                output = 0
            w0 = w0 + eta*(y[i] - output)
            w = w + eta*(y[i] - output)*X[i,]
            print(" w0 =", w0)
            print(" w =", w)
    return (w0, w)
            


# In[ ]:


my_perceptron(X, Y, 0.15, 20)


# # using sklearn

# In[50]:


import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.linear_model import Perceptron


# In[29]:


data = pd.read_csv('data_per.csv')
data


# In[31]:


data = np.array(data)


# In[44]:


X_train, X_test, y_train, y_test = train_test_split(data[:,0:5], data[:,5], random_state=1)


# In[49]:





# In[52]:


model = Perceptron()


# In[53]:


model.fit(X_train, y_train)


# In[54]:


model


# In[58]:


model.coef_


# In[59]:


model.intercept_


# In[60]:


model.n_iter_


# In[63]:


from sklearn.metrics import accuracy_score


# In[67]:


y_pre = model.predict(X_test)
accuracy_score(y_test, y_pre)


# In[ ]:





# In[ ]:





# In[ ]:




