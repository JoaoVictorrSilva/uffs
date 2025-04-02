def AFD(M, cadeia):
    Q, Sigma, delta, q0, F = M
    qA = q0
    for x in cadeia:
        if (qA, x) in delta:
            qA = delta[(qA, x)]
        else:
            return False
    return qA in F

class JogoCobrinha:
    
    def __init__(self):
        self.largura = 3
        self.altura = 3
        self.cobra = [(0, 0)]
        self.macas = (2, 2)
        
    def imprimir_tabuleiro(self):
        print('Tabuleiro 3x3')
        for y in range(self.altura):
            for x in range(self.largura):
                if (x, y) == self.cobra[0]:
                    print('C', end=' ')
                elif (x, y) == self.macas:
                    print('M', end=' ') 
                else:
                    print('.', end=' ') 
            print()
            
    def criar_funcao_transicao(self):
        delta = {}
        for x in range(self.largura):
            for y in range(self.altura):
                if (x, y) == self.macas:
                    continue
                delta[((x, y), 'W')] = (x, y - 1) if y > 0 else (x, y)
                delta[((x, y), 'S')] = (x, y + 1) if y < self.altura - 1 else (x, y)
                delta[((x, y), 'A')] = (x - 1, y) if x > 0 else (x, y)
                delta[((x, y), 'D')] = (x + 1, y) if x < self.largura - 1 else (x, y)
        return delta

    def iniciar(self):
        self.imprimir_tabuleiro()

        Q = [(x, y) for x in range(self.largura) for y in range(self.altura)]
        Sigma = ['W', 'A', 'S', 'D']
        delta = self.criar_funcao_transicao()
        q0 = self.cobra[0]
        F = [self.macas]
        M = (Q, Sigma, delta, q0, F)

        print('\nDigite todo o percurso da Cobra, com os seguintes comandos:')
        print('W - cima \nS - baixo \nA - esquerda \nD - direita \n0 - sair\n')

        cadeia = input('Digite a sequência de direções: ').strip().upper()

        if AFD(M, cadeia):
            print('String Aceita! Comeu a maçã!')
        else:
            print('String Não Aceita! Fim de Jogo.')

jogo = JogoCobrinha()
jogo.iniciar()