import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("colisoes.csv")
plt.plot(df["chaves"], df["colisoes"])
plt.xlabel("Chaves inseridas")
plt.ylabel("Colisões acumuladas")
plt.title("Tabela Hash para CPFs — Duplo Hash")
plt.grid(True)
plt.savefig("grafico.png", dpi=150)