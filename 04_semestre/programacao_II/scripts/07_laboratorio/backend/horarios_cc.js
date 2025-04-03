function createData(semester, hora, segunda, terca, quarta, quinta, sexta, sabado){
  return {semester, hora, segunda, terca, quarta, quinta, sexta, sabado}
}

const horarios_cc = [

  createData("1º Semestre Vespertino","13:30", "Introdução a Filosofia", "Informática Básica", "Matemática C", "Algoritmos e Programação", "Estatística Básica", " "),
  createData("1º Semestre Vespertino","16:10", "Algoritmos e Programação", "Estatística Básica", "Introdução a Filosofia", "Informática Básica", "Matemática C", " "),
  
  createData("1º Semestre Noturno","19:10", "Introdução a Filosofia", "Informática Básica", "Matemática C", "Algoritmos e Programação", "Estatística Básica", " "),
  
  createData("2º Semestre Vespertino","13:30", "Cálculo I", "Circuitos Digitais", "Geometria Analítica", "Estruturas de Dados", "Probabilidade e Estatística", " "),
  createData("2º Semestre Vespertino","16:20", "Circuitos Digitais", "Estruturas de Dados", "Cálculo I", "Probabilidade e Estatística", "Geometria Analítica"),
  createData("2º Semestre Vespertino","19:10", "Estruturas de Dados", " ", "Produção Textual"),

  createData("3º Semestre Noturno","19:10", "Programação I", "Cálculo II", "Matemática Discreta", "Sistemas Digitais", "Sistemas Digitais"),

  
  createData("4º Semestre Vespertino","13:30", "Organização de Computadores", "Grafos", "Banco de Dados I", "Engenharia de Software I", "Programação II"),
  createData("4º Semestre Vespertino","16:20", "Programação II", "Engenharia de Software I", "Organização de Computadores", "Grafos", "Banco de Dados I"),
  createData("4º Semestre Vespertino","19:10", " ", " ", "Iniciação à Prática Científica"),

  createData("5º Semestre Noturno","19:10", "Linguagens Formais e Autônomatos", "Banco de Dados II", "Álgebra Linear", "Sistemas Operacionais", "Engenharia de Software II"),

  createData("6º Semestre Vespertino","13:30", "Construção de Compiladores", "Planejamento e Gestão de Projetos", "História da Fronteira Sul", "Redes de Computadores", "Teoria da Computação"),
  createData("6º Semestre Vespertino","16:10", "Redes de Computadores", "Teoria da Computação", "História da Fronteira Sul", "Planejamento e Gestão de Projetos", "Construção de Compiladores"),
  
  createData("7º Semestre Noturno","19:10", "Cálculo Numérico", "Meio Ambiente e Diversidade", "Inteligência Artificial", "Computação Gráfica", "linguagens de Programação"),
  
  createData("8º Semestre Vespertino","10:20", " ", " ", " ", " ", " ", "TCC II"),
  createData("8º Semestre Vespertino","13:30", "Direito e Cidadania", " ", "Tópicos Especiais em Computação"),
  createData("8º Semestre Vespertino","16:10", " ", " ", "Tópicos Especiais em Computação"),
  createData("8º Semestre Vespertino","19:10", " ", " ", " ", " ", "(Curso de ADM) Gestão da Inovação"),
  
  createData("9º Semestre Noturno","07:30"," ", "(Curso de ADM) Empreendedorismo e criação de negócios"),
  createData("9º Semestre Noturno","10:20", " ", " ", " ", " ", " ", "TCC I"),
  createData("9º Semestre Noturno","19:10", "Tópicos Especiais em Computação XIII", " ", " ", "Tópicos Especiais em Computação XXXIII 40")
]

module.exports = horarios_cc;