import Header from "./Header/Header";

function Cc(){
  return (
    <div class="container-fluid">

    <Header/>
  
    <h1 class="h1-cursos">Ciências da Computação:</h1>
    <nav>
      <ul>
        <li><a href="#1-v">1º Semestre Vespertino</a></li>
        <li><a href="#1-n">1º Semestre Noturno</a></li>
        <li><a href="#2-v">2º Semestre Vespertino</a></li>
        <li><a href="#3-n">3º Semestre Noturno</a></li>
        <li><a href="#4-v">4º Semestre Vespertino</a></li>
        <li><a href="#5-n">5º Semestre Noturno</a></li>
        <li><a href="#6-v">6º Semestre Vespertino</a></li>
        <li><a href="#7-n">7º Semestre Noturno</a></li>
        <li><a href="#8-v">8º Semestre Vespertino</a></li>
        <li><a href="#9-n">9º Semestre Noturno</a></li>
      </ul>
    </nav>
  
    <section>
      <h3>1º Semestre Vespertino</h3>
      <table id="1-v" class="table">
      <thead>
        <tr>
          <th scope="col">Horário</th>
          <th scope="col">Segunda</th>
          <th scope="col">Terça</th>
          <th scope="col">Quarta</th>
          <th scope="col">Quinta</th>
          <th scope="col">Sexta</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th scope="row">13:30</th>
          <td>Introdução a filosofia <br/>Luciana Vanuza Gobi</td>
          <td>Informática Básica <br/>Felipe Grando</td>
          <td>Matemática C <br/>Ana Maria Basei</td>
          <td>Algoritmos e Programação <br/>Andressa Sebben</td>
          <td>Estatísca Básica <br/>Tainara Volan</td>
        </tr>
        <tr>
          <th scope="row">16:20</th>
          <td>Algoritmos e Programação <br/>Andressa Sebben</td>
          <td>Estatísca Básica <br/>Tainara Volan</td>
          <td>Introdução a filosofia <br/>Luciana Vanuza Gobi</td>
          <td>Informática Básica <br/>Felipe Grando</td>
          <td>Matemática C <br/>Ana Maria Basei</td>
        </tr>
      </tbody>
    </table>
    </section>
  
    <section>
    <h3>1º Semestre Noturno</h3>
      <table id="1-n" class="table">
      <thead>
        <tr>
          <th scope="col">Horário</th>
          <th scope="col">Segunda</th>
          <th scope="col">Terça</th>
          <th scope="col">Quarta</th>
          <th scope="col">Quinta</th>
          <th scope="col">Sexta</th>
        </tr>
      </thead>
      <tbody>    
        <tr>
          <th scope="row">19:10</th>
          <td>Introdução a filosofia <br/>Luciana Vanuza Gobi</td>
          <td>Informática Básica <br/>Claunir Pavan</td>
          <td>Matemática C <br/>Divane Marcon</td>
          <td>Algoritmos e Programação <br/>Felipe Grando</td>
          <td>Estatísca Básica <br/>Leandro Bordin</td>
        </tr>
      </tbody>
    </table>
    </section>
  
    <section>
      <h3>2º Semestre Vespertino</h3>
      <table id="2-v" class="table">
      <thead>
        <tr>
          <th scope="col">Horário</th>
          <th scope="col">Segunda</th>
          <th scope="col">Terça</th>
          <th scope="col">Quarta</th>
          <th scope="col">Quinta</th>
          <th scope="col">Sexta</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th scope="row">13:30</th>
          <td>Cáculo I<br/>Lucia Menoncini</td>
          <td>Circuitos Digitais<br/>Luciano L. Caimi</td>
          <td>Geometria Analítica<br/>Ana Maria Basei</td>
          <td>Estruturas de Dados<br/>Claunir Pavan</td>
          <td>Probabilidade e Estatísca<br/>Volante</td>
        </tr>
        <tr>
          <th scope="row">16:20</th>
          <td>Circuitos Digitais<br/>Luciano L. Caimi</td>
          <td>Estruturas de Dados<br/>Claunir Pavan</td>
          <td>Cáculo I<br/>Lucia Menoncini</td>
          <td>Probabilidade e Estatísca<br/>Volante</td>
          <td>Geometria Analítica<br/>Ana Maria Basei</td>
        </tr>
        <tr>
          <th scope="row">19:10</th>
          <td>Estruturas de Dados<br/>Claunir Pavan</td>
          <td></td>
          <td>Produção Textual<br/>Mary Neiva</td>
          <td></td>
          <td></td>
        </tr>
      </tbody>
    </table>
    </section>
  
    <section>
      <h3>3º Semestre Noturno</h3>
        <table id="3-n" class="table">
        <thead>
          <tr>
            <th scope="col">Horário</th>
            <th scope="col">Segunda</th>
            <th scope="col">Terça</th>
            <th scope="col">Quarta</th>
            <th scope="col">Quinta</th>
            <th scope="col">Sexta</th>
          </tr>
        </thead>
        <tbody>    
          <tr>
            <th scope="row">19:10</th>
            <td>Programação I<br/>Samuel Feitosa</td>
            <td>Cálculo II<br/>Edson R. dos Santos</td>
            <td>Matemática Discreta<br/>Rosane Binotto</td>
            <td>Sistemas Digitais<br/>Geomar Screiner</td>
            <td>Sistemas Digitais<br/>Guilherme Dal Bianco</td>
          </tr>
        </tbody>
      </table>
    </section>
  
    <section>
      <h3>4º Semestre Vespertino</h3>
      <table id="4-v" class="table">
      <thead>
        <tr>
          <th scope="col">Horário</th>
          <th scope="col">Segunda</th>
          <th scope="col">Terça</th>
          <th scope="col">Quarta</th>
          <th scope="col">Quinta</th>
          <th scope="col">Sexta</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th scope="row">13:30</th>
          <td>Organização de Computadores<br/>Luciano L. Caimi</td>
          <td>Grafos<br/>Andrei de Almeida</td>
          <td>Banco de Dados 1<br/>Denio Duarte</td>
          <td>Engenharia de Software 1<br/>Marina Girolimetto</td>
          <td>Programação 2<br/>Giancalo Salton</td>
        </tr>
        <tr>
          <th scope="row">16:20</th>
          <td>Programação 2<br/>Giancalo Salton</td>
          <td>Engenharia de Software 1<br/>Marina Girolimetto</td>
          <td>Organização de Computadores<br/>Luciano L. Caimi</td>
          <td>Grafos<br/>Andrei de Almeida</td>
          <td>Banco de Dados 1<br/>Denio Duarte</td>
        </tr>
        <tr>
          <th scope="row">19:20</th>
          <td></td>
          <td></td>
          <td>Iniciação à prática Científica<br/>Marina Girolimetto</td>
          <td></td>
          <td></td>
        </tr>
      </tbody>
    </table>
    </section>
  
    <section>
      <h3>5º Semestre Noturno</h3>
        <table id="5-n" class="table">
        <thead>
          <tr>
            <th scope="col">Horário</th>
            <th scope="col">Segunda</th>
            <th scope="col">Terça</th>
            <th scope="col">Quarta</th>
            <th scope="col">Quinta</th>
            <th scope="col">Sexta</th>
          </tr>
        </thead>
        <tbody>    
          <tr>
            <th scope="row">19:10</th>
            <td>Linguagens Formais e Autômatos<br/>Braulio A. de Mello</td>
            <td>Banco de dados 2<br/>Guilherme Dal Bianco</td>
            <td>Álgebra Linear<br/>Edson R. dos Santos</td>
            <td>Sistemas Operacionais<br/>Marco Aurelio Spohn</td>
            <td>Engenharia de Software 2<br/>Marina Girolimetto</td>
          </tr>
        </tbody>
      </table>
    </section>
  
    <section>
      <h3>6º Semestre Vespertino</h3>
      <table id="6-v" class="table">
      <thead>
        <tr>
          <th scope="col">Horário</th>
          <th scope="col">Segunda</th>
          <th scope="col">Terça</th>
          <th scope="col">Quarta</th>
          <th scope="col">Quinta</th>
          <th scope="col">Sexta</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th scope="row">13:30</th>
          <td>Construção de Compiladores<br/>Braulio A. de Mello</td>
          <td>Planejamento e Gestão de Projetos<br/>Edimar Roque</td>
          <td>História da Fronteira Sul</td>
          <td>Redes de Computadores<br/>Marco Aurelio Spohn</td>
          <td>Teoria da Computação<br/>Andrei de Almeida</td>
        </tr>
        <tr>
          <th scope="row">16:20</th>
          <td>Redes de Computadores<br/>Marco Aurelio Spohn</td>
          <td>Teoria da Computação<br/>Andrei de Almeida</td>
          <td>História da Fronteira Sul</td>
          <td>Planejamento e Gestão de Projetos<br/>Edimar Roque</td>
          <td>Construção de Compiladores<br/>Braulio A. de Mello</td>
        </tr>
      </tbody>
    </table>
    </section>
  
    <section>
      <h3>7º Semestre Noturno</h3>
        <table id="7-n" class="table">
        <thead>
          <tr>
            <th scope="col">Horário</th>
            <th scope="col">Segunda</th>
            <th scope="col">Terça</th>
            <th scope="col">Quarta</th>
            <th scope="col">Quinta</th>
            <th scope="col">Sexta</th>
          </tr>
        </thead>
        <tbody>    
          <tr>
            <th scope="row">19:10</th>
            <td>Cálculo Numérico<br/>Vitor Petry</td>
            <td>Meio Ambiente e Diversidade<br/>Péricles L. Brustolin</td>
            <td>Inteligência Artificial<br/>Felipe Grando</td>
            <td>Computação Gráfica<br/>Marina Girolimetto</td>
            <td>Linguagens de Programação<br/>Samuel Feitosa</td>
          </tr>
        </tbody>
      </table>
    </section>
  
    <section>
      <h3>8º Semestre Vespertino</h3>
      <table id="8-v" class="table">
      <thead>
        <tr>
          <th scope="col">Horário</th>
          <th scope="col">Segunda</th>
          <th scope="col">Quarta</th>
          <th scope="col">Quinta</th>
          <th scope="col">Sexta</th>
          <th scope="col">Sábado</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th scope="row">10:20</th>
          <td></td>
          <td></td>
          <td></td>
          <td></td>
          <td>TCC 2 <br/>Guilherme Dal Bianco</td>
  
        </tr>
        <tr>
          <th scope="row">13:30</th>
          <td>Direito e Cidadania</td>
          <td>Tópicos Especiais em Computação <br/>Geomar Schreiner</td>
          <td></td>
          <td></td>
          <td></td>
        </tr>
        <tr>
          <th scope="row">16:20</th>
          <td></td>
          <td></td>
          <td>Tópicos Especiais em Computação <br/>Geomar Schreiner</td>
          <td></td>
          <td></td>
        </tr>
        <tr>
          <th scope="row">19:20</th>
          <td></td>
          <td></td>
          <td></td>
          <td>(Curso de ADM) Gestão da Inovação <br/>Matrícula via link: shorturl.at/jrE46</td>
          <td></td>
        </tr>
      </tbody>
    </table>
    </section>
  
    <section>
      <h3>9º Semestre Noturno</h3>
      <table id="9-n" class="table">
      <thead>
        <tr>
          <th scope="col">Horário</th>
          <th scope="col">Segunda</th>
          <th scope="col">Terça</th>
          <th scope="col">Quinta</th>
          <th scope="col">Sábado</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th scope="row">07:30</th>
          <td></td>
          <td>(Curso de ADM) <br/>Empreendedorismo e criação de negócios <br/>Matrícula via link shorturl.at/pDGPX</td>
          <td></td>
          <td></td>

        </tr>
        <tr>
          <th scope="row">10:20</th>
          <td></td>
          <td></td>
          <td></td>
          <td>TCC 1 <br/>Braulio A. de Mello</td>
        </tr>
        <tr>
          <th scope="row">19:20</th>
          <td>Tópicos Especiais em Computação XIII <br/>Marco Aurelio Spohn</td>
          <td></td>
          <td>Tópicos Especiais em Computação XXXIII 40<br/>Giancalo Salton</td>
          <td></td>
        </tr>
      </tbody>
    </table>
    </section>

  </div>
  );
}

export default Cc;