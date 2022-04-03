import matplotlib.pyplot as plt
import metnum
import numpy as np

def tss(y):
    m = np.mean(y)
    res = 0
    for y_i in y:
        res += ((y_i - m)**2)
    return res    

   
def rss(y, y_pred):
    res = 0
    for i in range(len(y)):
        res += ((y[i] - y_pred[i])**2)
    return res   

def run_analysis(X, y):
    # CML
    #X = [df[targets[i]].values for i in range(len(targets))]
    #y = df["Life expectancy"].values.reshape(-1, 1)
    
    clf = metnum.CML()
    clf.fit(X, y)
    y_pred = clf.predict(X)
    
    plot(y, y_pred)
    
    # R^2 y R^2 ajustado
    tss_res = tss(y)
    rss_res = rss(y, y_pred)
    N = len(y)
    p = X.shape[1]
    R2 = (tss_res-rss_res) / tss_res 
    print("R2:", R2)
    R2_ajustado = 1 - (1-R2)*(N-1)/(N-p-1)
    
    # RSE
    RSE = np.sqrt(1/(N-2) * rss_res)
    
    print("R2 ajustado:", R2_ajustado)
    print("RSE:", RSE)

    return clf.coef()


def plot(y, y_pred):
    
    # Residual vs fitted values
    residuals = y - y_pred
    plt.scatter(residuals, y_pred)
    plt.title("Residual vs fitted values")
    plt.xlabel("Fitted values")
    plt.ylabel("Residual")
    plt.show()
    
    
    
