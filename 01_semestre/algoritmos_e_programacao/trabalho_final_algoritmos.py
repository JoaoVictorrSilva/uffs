#FUNÇÃO P/ TÍTULO:
def título(txt):
  print()
  print('=' * len(txt))
  print(txt)
  print('=' * len(txt))
  print()


#FUNÇÃO P/ ACHAR O INDICE DO PRODUTO:
def consulta(codigo):
  contador = 0
  for indice in range(len(lista_produtos)):
    if codigo == lista_produtos[indice].código:
      return int(indice)
    else:
      contador += 1
  if contador == len(lista_produtos):
    return int(contador)


#CLASSE P/ ADD NOVO PRODUTO:
class ADD_produtos:
  código = None
  nome = None
  tipo = None
  gênero = None
  lançamento = None
  preço = None
  disponível = None

#CLASSE P/ SALVAR ALGUNS PRODUTOS NA MEMÓRIA:
class MMR_produtos:
  def __init__(self, código, nome, tipo, gênero, lançamento, preço, disponível):
    self.código = código
    self.nome = nome
    self.tipo = tipo
    self.gênero = gênero
    self.lançamento = lançamento
    self.preço = preço
    self.disponível = disponível

#CLASSE PARA REGISTRO DE COMPRA:
class Registro:
  nome = None
  login = None
  data = None
  total = None 

#PRODUTOS MEMÓRIA
prod_1 = MMR_produtos(1111, 'MATRIX', 2, 'AÇÃO, FICÇÃO CIENTÍFICA, AVENTURA, FANTASIA', 1999, 12.99, True)
prod_2 = MMR_produtos(2222, 'AVATAR', 2, 'AÇÃO, FICÇÃO CIENTÍFICA, AVENTURA, FANTASIA', 2009, 15.99, False)
prod_3 = MMR_produtos(3333, 'DARK', 1, 'SUSPENSE, DRAMA, MISTÉRIO', 2017, 9.99, True)
prod_4 = MMR_produtos(4444, 'THE WALKING DEAD', 1, 'SUSPENSE, DRAMA, TERROR, FICÇÃO PÓS-APOCALÍPTICA', 2010, 13.99,True)
prod_5 = MMR_produtos(5555, 'O DILEMA DAS REDES', 3, 'DOCUMENTÁRIO, CIÊNCIA E NATUREZA', 2020, 12.99, False)
prod_6 = MMR_produtos(6666, 'NEYMAR - O CAOS PERFEITO', 3, 'DOCUMENTÁRIOS SÓCIOCULTURAIS', 2022, 19.99,True)
prod_7 = MMR_produtos(7777, 'CARROS' , 2, 'AÇÃO, AVENTURA, FANTASIA', 2006, 29.99, True)
prod_8 = MMR_produtos(8888, 'STRANGER THINGS', 1, 'SUSPENSE, AVENTURA, ACÃO', 2016, 15.99, False)
prod_9 = MMR_produtos(9999,'TÁ CHOVENDO HAMBÚRGUER', 2, 'CÓMEDIA, FANTASIA, AÇÃO', 2009, 8.99, True)
prod_10 = MMR_produtos(1000,'ILHA DAS FLORES', 3, 'DOCUMENTÁRIOS INFORMATIVOS', 1989, 7.99, True)

#LISTA GERAIS:
lista_produtos = [prod_1, prod_2, prod_3, prod_4, prod_5, prod_6,prod_7, prod_8, prod_9, prod_10]
lista_registro = []

#O QUE O FUNCIONÁRIO DESEJA FAZER:
while True:
  título('PAINEL DE CONTROLE DO FUNCIONÁRIO')
  print('\n1 - Para cadastrar um produto \n2 - Para consultar um produto \n3 - Para atualizar um produto\n4 - Para visualizar um relatório dos produtos\n5 - Para registrar compra\n6 - Para um relatório de compras\nDigite outro valor para encerrar o programa\n')
  ação = str(input('O que deseja fazer: '))
  if ação != '1' and ação != '2' and ação != '3' and ação != '4' and ação != '5' and ação != '6':
    break

#PROGRAMA PARA ADD UM NOVO PRODUTO:
  if ação == '1':
    título('ADICIONANDO PRODUTO')
    while True:
      novo = ADD_produtos()

      #CÓDIGO PRODUTO
      novo.código = int(input('Digite um código para o produto (0 para sair): '))
      if novo.código == 0:
        break
      for indice in range(len(lista_produtos)):
        while novo.código == lista_produtos[indice].código or novo.código < 0:
          print("\n⚠️ CÓDIGO INDISPONÍVEL ⚠️\n")
          novo.código = int(input('Digite um código válido (0 para sair): '))
      if novo.código == 0:
        break

      #TIPO DO PRODUTO
      novo.tipo = int(input('Tipo do produto (1 para série, 2 para filme, 3 para documentário): '))
      while novo.tipo != 1 and novo.tipo != 2 and novo.tipo != 3:
        print("\n⚠️ TIPO INDISPONÍVEL ⚠️\n")
        novo.tipo = int(input('Digite um tipo válido! (1 para série, 2 para filme, 3 para documentário): '))

      #NOME PRODUTO/GÊNERO
      novo.nome = str(input('Digite um nome para o produto: ')).upper()
      novo.gênero = str(input('Gênero: ')).upper()

      #LANÇAMENTO PRODUTO    
      novo.lançamento = int(input('Ano de lançamento: '))
      while novo.lançamento > 2030 or novo.lançamento < 1895:
        print("\n⚠️ DATA INVÁLIDA ⚠️\n")
        novo.lançamento = int(input('Ano de lançamento: '))

      #PREÇO PRODUTO
      novo.preço = float(input('Preço do produto: R$'))
      while novo.preço < 0.00:
        print("\n⚠️ PREÇO INVÁLIDO ⚠️\n")
        novo.preço = float(input('Digite um preço válido para o produto: R$'))

      #DISPONIBILIDADE DO PRODUTO
      disponível = int(input('Produto pode ser vendido nesse momento (1 - SIM, 2 - NÃO): '))
      while disponível != 1 and disponível != 2:
        print("\n⚠️ AÇÃO INDISPONÍVEL ⚠️\n")
        disponível = int(input('Produto pode ser vendido nesse momento (1 - SIM, 2 - NÃO): '))
      if disponível == 1:
        novo.disponível = True
      else:
        novo.disponível = False
      
      #SALVANDO PRODUTO
      lista_produtos.append(novo)     
      título('⭐ PRODUTO CADASTRADO COM SUCESSO ⭐')
    
#PROGRAMA PARA CONSULTAR UM PRODUTO:
  if ação == '2':
    título('CONSULTANDO PRODUTO')
    while True:
      ação_2 = int(input('\nDigite o código do produto que deseja consultar (ou 0 para sair): '))
      if ação_2 == 0:
        break

      #ACHAR O INDICE DO PRODUTO    
      código_2 = consulta(ação_2)
      while código_2 == len(lista_produtos):
        print('\n⚠️ PRODUTO NÃO CADASTRADO ⚠️')
        ação_2 = int(input('\nDigite o código do produto que deseja consultar (ou 0 para sair): '))
        if ação_2 == 0:
          break
        else:
          código_2 = consulta(ação_2)
      if ação_2 == 0:
          break

      if ação_2 == lista_produtos[código_2].código:
        if lista_produtos[código_2].tipo == 1:
          print(f'\nTIPO PRODUTO: SÉRIE')
        elif lista_produtos[código_2].tipo == 2:
          print(f'\nTIPO PRODUTO: FILME')
        else:
          print(f'\nTIPO PRODUTO: DOCUMENTÁRIO')
        print(f'NOME PRODUTO: {lista_produtos[código_2].nome}'),
        print(f'LANÇAMENTO PRODUTO: {lista_produtos[código_2].lançamento}')
        print(f'GÊNERO PRODUTO: {lista_produtos[código_2].gênero}')
        print('DISPONIBILIDADE: DISPONÍVEL') if lista_produtos[código_2].disponível == True else print('DISPONIBILIDADE: INDISPONÍVEL')
        print(f'PREÇO: R${lista_produtos[código_2].preço}')

# PROGRAMA PARA ATUALIZAR UM PRODUTO:
  if ação == '3':
    título('ATUALIZANDO PRODUTO')
    while True:
      código_3 = int(input('Digite o código do produto que deseja atualizar (0 para sair): '))
      if código_3 == 0:
        break

      #INDICE PRODUTO
      indice = consulta(código_3)

      #PRODUTO N/ CADASTRADO 
      while indice == len(lista_produtos):
        print('\n⚠️ PRODUTO NÃO CADASTRADO ⚠️\n')
        código_3 = int(input('Digite um código válido (0 para sair): '))
        indice = consulta(código_3)
        if código_3 == 0:
          break
      if código_3 == 0:
          break

      #RELATÓRIO DO PRODUTO
      if código_3 == lista_produtos[indice].código:
        print(f'\nCÓDIGO PRODUTO: {lista_produtos[indice].código}')
        if lista_produtos[indice].tipo == 1:
          print(f'TIPO PRODUTO: SÉRIE')
        elif lista_produtos[indice].tipo == 2:
          print(f'TIPO PRODUTO: FILME')
        else:
          print(f'TIPO PRODUTO: DOCUMENTÁRIO')
        print(f'NOME PRODUTO: {lista_produtos[indice].nome}')
        print(f'LANÇAMENTO PRODUTO: {lista_produtos[indice].lançamento}')
        print(f'GÊNERO PRODUTO: {lista_produtos[indice].gênero}')
        print('DISPONIBILIDADE: DISPONÍVEL') if lista_produtos[indice].disponível == True else print('DISPONIBILIDADE: INDISPONÍVEL')
        print(f'PREÇO: R${lista_produtos[indice].preço}\n')
      
      while True:
        print('1 - Para alterar o nome\n2 - Para alterar o tipo\n3 - Para alterar o lançamento\n4 - Para alterar o gênero\n5 - Para alterar a disponibilidade\n6 - Para alterar o preço\n')
        #O QUE SERÁ ALTERADO:      
        alterar = str(input('ALTERAR: '))
        if alterar != '1' and alterar != '2' and alterar != '3' and alterar != '4' and alterar != '5' and alterar != '6':
          break

        #NOME
        if alterar == '1':
          lista_produtos[indice].nome = str(input('\nNovo nome: ')).upper()
      
        #TIPO
        elif alterar == '2':
          lista_produtos[indice].tipo = int(input("\nNovo tipo (1 para série, 2 para filme, 3 para documentário: "))
          while lista_produtos[indice].tipo != 1 and lista_produtos[indice].tipo != 2 and lista_produtos[indice].tipo != 3:
            print("\n⚠️ TIPO INDISPONÍVEL ⚠️\n")
            lista_produtos[indice].tipo = int(input('Digite um tipo válido! (1 para série, 2 para filme, 3 para documentário): '))

        #LANÇAMENTO           
        elif alterar == '3':
          lista_produtos[indice].lançamento = int(input("\nLançamento: "))
          while lista_produtos[indice].lançamento > 2030 or lista_produtos[indice].lançamento < 1895:
            print("\n⚠️ DATA INVÁLIDA ⚠️\n")
            lista_produtos[indice].lançamento = int(input('Ano de lançamento: '))
      
        #GÊNERO
        elif alterar == '4':
          lista_produtos[indice].gênero = str(input("\nNovo gênero: ")).upper()

        #DISPONIBILIDADE
        elif alterar == '5':
          disponível = int(input("\n1 - PARA DISPONÍVEL, 2 - INDISPONÍVEL: "))
          while disponível != 1 and disponível != 2:
            print("\n⚠️ AÇÃO INDISPONÍVEL ⚠️\n")
            disponível = int(input('\n1 - PARA DISPONÍVEL, 2 - INDISPONÍVEL: '))
          if disponível == 1:
            lista_produtos[indice].disponível = True
          else:
            lista_produtos[indice].disponível = False
      
        #PREÇO
        else:
          lista_produtos[indice].preço = float(input('\nNovo preço: R$'))
          while lista_produtos[indice].preço < 0.00:
            print('\n⚠️ PREÇO INVÁLIDO ⚠️\n')
            novo.preço = float(input('Preço do produto: '))

        continuar = str(input('\nDESEJA CONTINUAR ATUALIZANDO O PRODUTO[S/N]: ')).upper()
        while continuar != 'S' and continuar != 'N':
          print('\nAÇÃO INVÁLIDA')
          continuar = str(input('\nDESEJA CONTINUAR ATUALIZANDO O PRODUTO[S/N]: ')).upper()
        if continuar == 'N':
          break

      título('PRODUTO ATUALIZADO COM SUCESSO ✔️')      

#PROGRAMA PARA VISUALIZAR UM RELATÓRIO DOS PRODUTOS:
  if ação == '4':
    título('RELATÓRIO DE PRODUTOS')
    while True:
      código_4 = str(input('\n0 - Para visualizar todos os produtos\n1 - Para visualizar os filmes\n2 - Para visalizar as séries\n3 - Para visualizar os documentários\n4 - Para visualizar os produtos disponíveis para venda\n5 - Para visualizar os produtos indisponíveis\nDigite outro valor para sair\n\nO que deseja fazer: '))
      print()
      if código_4 != '0' and código_4 != '1' and código_4 != '2' and código_4 != '3' and código_4 != '4' and código_4 != '5':
        break
      
      #RELATÓRIO GERAL
      elif código_4 == '0':
        título('RELATÓRIO GERAL')
        relatório_geral = lista_produtos
        print("{:<30} {:<15} {:<10} {:<12} ".format('NOME','TIPO','CÓDIGO', 'PREÇO'))
        relatório_geral.sort(key=lambda v: v.nome)
        for v in relatório_geral:
          if v.tipo == 1:
            print("{:<30} {:<15} {:<10} {:<12}".format(v.nome, 'SÉRIE', v.código, v.preço))
          elif v.tipo == 2:
            print("{:<30} {:<15} {:<10} {:<12}".format(v.nome, 'FILME', v.código, v.preço))
          else:
            print("{:<30} {:<15} {:<10} {:<12}".format(v.nome, 'DOCUMENTÁRIO', v.código, v.preço))

      #RELATÓRIO FILMES
      elif código_4 == '1':
        título('RELATÓRIO FILMES')
        relatório_filmes = []
        for i in range(len(lista_produtos)):
          if lista_produtos[i].tipo == 2:
            relatório_filmes.append(lista_produtos[i])
        print("{:<30} {:<15} {:<10} {:<12} ".format('NOME','TIPO','CÓDIGO','PREÇO'))
        relatório_filmes.sort(key=lambda v: v.nome)
        for v in relatório_filmes:
          print("{:<30} {:<15} {:<10} {:<12}".format(v.nome, 'FILME', v.código, v.preço))

      #RELATÓRIO SÉRIES
      elif código_4 == '2':
        título('RELATÓRIO SÉRIES')
        relatório_séries = []
        for i in range(len(lista_produtos)):
          if lista_produtos[i].tipo == 1:
            relatório_séries.append(lista_produtos[i])
        print("{:<30} {:<15} {:<10} {:<12} ".format('NOME','TIPO','CÓDIGO','PREÇO'))
        relatório_séries.sort(key=lambda v: v.nome)
        for v in relatório_séries:
          print("{:<30} {:<15} {:<10} {:<12}".format(v.nome, 'SÉRIE', v.código, v.preço))

      #RELATÓRIO DOCUMENTÁRIOS
      elif código_4 == '3':
        título('RELATÓRIO DOCUMENTÁRIOS')
        relatório_documentários = []
        for i in range(len(lista_produtos)):
          if lista_produtos[i].tipo == 3:
            relatório_documentários.append(lista_produtos[i])
        print("{:<30} {:<15} {:<10} {:<12} ".format('NOME','TIPO','CÓDIGO','PREÇO'))
        relatório_documentários.sort(key=lambda v: v.nome)
        for v in relatório_documentários:
          print("{:<30} {:<15} {:<10} {:<12}".format(v.nome, 'DOCUMENTÁRIO', v.código, v.preço))
      
      #RELATÓRIO DISPONÍVEIS
      elif código_4 == '4':
        título('RELATÓRIO DISPONÍVEIS PARA VENDA')
        relatório_disponível = []
        for i in range(len(lista_produtos)):
          if lista_produtos[i].disponível == True:
            relatório_disponível.append(lista_produtos[i])
        print("{:<30} {:<15} {:<10} {:<12} ".format('NOME','TIPO','CÓDIGO','PREÇO'))
        relatório_disponível.sort(key=lambda v: v.nome)
        for v in relatório_disponível:
          if v.tipo == 1:
            print("{:<30} {:<15} {:<10} {:<12}".format(v.nome, 'SÉRIE', v.código, v.preço))
          elif v.tipo == 2:
            print("{:<30} {:<15} {:<10} {:<12}".format(v.nome, 'FILME', v.código, v.preço))
          else:
            print("{:<30} {:<15} {:<10} {:<12}".format(v.nome, 'DOCUMENTÁRIO', v.código, v.preço))

      #RELATÓRIO INDISPONÍVEIS
      else:
        título('RELATÓRIO INDISPONÍVEIS PARA VENDA')
        relatório_indisponível = []
        for i in range(len(lista_produtos)):
          if lista_produtos[i].disponível == False:
            relatório_indisponível.append(lista_produtos[i])
        print("{:<30} {:<15} {:<10} {:<12} ".format('NOME','TIPO','CÓDIGO','PREÇO'))
        relatório_indisponível.sort(key=lambda v: v.nome)
        for v in relatório_indisponível:
          if v.tipo == 1:
            print("{:<30} {:<15} {:<10} {:<12}".format(v.nome, 'SÉRIE', v.código, v.preço))
          elif v.tipo == 2:
            print("{:<30} {:<15} {:<10} {:<12}".format(v.nome, 'FILME', v.código, v.preço))
          else:
            print("{:<30} {:<15} {:<10} {:<12}".format(v.nome, 'DOCUMENTÁRIO', v.código, v.preço))

# PROGRAMA PARA REGISTRAR COMPRA:
  if ação == '5':
    título('REGISTRANDO COMPRA')
    lista_compra = []
    código_produto = -1
    while código_produto != 0:

      #REGITRAR DATA
      nova_compra = Registro()
      import datetime
      data = datetime.date.today()
      nova_compra.data = (f'{data.day}/{data.month}/{data.year}')

      #CADASTRO CLIENTE
      cadastro = input('O cliente já possiu cadastro [S/N]? ').upper()
      while cadastro != 'N' and cadastro != 'S':
        print('\nAÇÃO INVÁLIDA\n')
        cadastro = input('O cliente já possiu cadastro [S/N]? ').upper()
      
      #CRIANDO UM LOGIN
      if cadastro == 'N':
        título('INICIANDO CADASTRO')
        nova_compra.nome = str(input('Digite o nome do cliente: ')).upper()
        while True:
          nome = str(input(f'O NOME: {nova_compra.nome}, ESTÁ CORRETO [S/N]? ')).upper()
          while nome != 'N' and nome != 'S':
            print('AÇÃO INVÁLIDA')
            nome = str(input(f'\nO NOME: {nova_compra.nome} ESTÁ CORRETO [S/N]? ')).upper()
          if nome == 'S':
            break
          else:
            nova_compra.nome = str(input('Digite o nome do cliente: ')).upper()

        nova_compra.login = str(input('Digite o CPF do cliente para registrar como o login (EXEMPLO: 000.000.000-00): '))
        while len(nova_compra.login) < 14 or len(nova_compra.login) > 14:
          print('\nCPF INVÁLIDO\n')
          nova_compra.login = str(input('Digite um CPF válido (0 para sair): '))
          if nova_compra.login == '0':
            break
        if nova_compra.login == '0':
            break
        while True:
          cpf = str(input(f'O CPF: {nova_compra.login}, ESTÁ CORRETO [S/N]? ')).upper()
          while cpf != 'N' and cpf != 'S':
            cpf = str(input(f'\nO CPF: {nova_compra.login} ESTÁ CORRETO [S/N]? ')).upper()
          if cpf == 'S':
            break
          else:
            nova_compra.login = str(input('Digite o CPF do cliente para registrar como o login (EXEMPLO: 000.000.000-00): '))
            while len(nova_compra.login) < 14 or len(nova_compra.login) > 14:
              print('\nCPF INVÁLIDO\n')
              nova_compra.login = str(input('Digite o CPF do cliente para registrar como o login: '))

        título('⭐ CLIENTE CADASTRADO COM SUCESSO ⭐')
      
      #BUSCANDO LOGIN
      else:
        nova_compra.login = str(input('\nDigite o login do cliente (0 para sair): '))
        if nova_compra.login == '0':
          break
        
        contador = 0
        for indice in range(len(lista_registro)):
          if lista_registro[indice].login == nova_compra.login:
            print(f'\nCLIENTE: {lista_registro[indice].nome}')
            break
          else:
            contador += 1
        
        while contador == len(lista_registro):
          print('\n⚠️ LOGIN NÃO ENCONTRADO ⚠️')
          nova_compra.login = str(input('\nDigite novamente o login (0 para sair): '))
          if nova_compra.login == '0':
            break
        if nova_compra.login == '0':
          break

      #COMPRA PRODUTO
      while True:
        título('REGISTRANDO COMPRA')
        código_produto = int(input('\nCÓDIGO DO PRODUTO (0 PARA SAIR): '))
      
      #BUSCA PRODUTO
        indice = consulta(código_produto)
        while len(lista_produtos) == indice and código_produto != 0:
          print(f'\n⚠️ PRODUTO NÃO CADASTRADO ⚠️\n')
          código_produto = int(input('\nDIGITE UM CÓDIGO VÁLIDO (0 PARA SAIR): '))
          indice = consulta(código_produto)

        #EXIBIR O CUPOM
        if código_produto == 0:  
          if len(lista_compra) > 0:
            título('⭐ COMPRA REALIZADA ⭐ ')
            título('CUPOM CLIENTE:')
            total = 0
            for i in range(len(lista_compra)):
              total += lista_compra[i].preço
            nova_compra.total = f'{total:.2f}'         
            print("\n{:<30} {:<15} {:<10} {:<12} ".format('NOME', 'TIPO', 'CÓDIGO', 'PREÇO'))
            for v in lista_compra:
              if v.tipo == 1:
                print("{:<30} {:<15} {:<10} {:<12}".format(v.nome, 'SÉRIE', v.código, v.preço))
              elif v.tipo == 2:
                print("{:<30} {:<15} {:<10} {:<12}".format(v.nome, 'FILME', v.código, v.preço))
              else:
                print("{:<30} {:<15} {:<10} {:<12}".format(v.nome, 'DOCUMENTÁRIO', v.código, v.preço))
            print()
            print(f'                                               TOTAL:    R${total:.2f}')

            lista_registro.append(nova_compra)
          break

        #SALVAR COMPRAS 
        else:
          if código_produto == lista_produtos[indice].código and lista_produtos[indice].disponível == True:
            print(f'PRODUTO: {lista_produtos[indice].nome}')
            comprar = input('ADICIONAR AO CARRINHO [S/N]? ').upper()
            while comprar != 'N' and comprar != 'S':
              print('AÇÃO INDISPONÍVEL')
              comprar = input('Adiocionar o produto ao carrinho [S/N]? ').upper()
            if comprar == 'S':
              lista_compra.append(lista_produtos[indice])
              print('PRODUTO ADD AO CARRINHO ✔️')
          elif código_produto == lista_produtos[indice].código and lista_produtos[indice].disponível == False:
            print(f'\n⚠️ PRODUTO: {lista_produtos[indice].nome}, INDISPONÍVEL| NÃO FOI POSSÍVEL REGISTRAR A COMPRA ⚠️')
        
      if código_produto == 0:
        break

#RELATÓRIO DE COMPRAS
  if ação == '6':
    if len(lista_registro) > 0:
      título('RELATÓRIO DE COMPRAS')
      print("{:<15} {:<15} {:<10}".format('LOGIN', 'DATA', 'TOTAL'))
      for v in lista_registro:
        print("{:<15} {:<15} {:<10}".format(v.login, v.data, v.total))
    else:
      título('SEM REGISTROS')