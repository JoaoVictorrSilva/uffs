import Cc from "./Cc";
import Header from "./Header/Header";

function App(){
  return (

    <div class="row">
      <Header/>
      <h1 class="h1-cursos">Cursos:</h1>
  
      <div class="col d-flex justify-content-center">
        <nav>
          <ul>
            <li><a href="#adm">Administração</a></li>
            <li><a href="#agro">Agronomia</a></li>
            <li><a href="cc.js">Ciências da Computação</a></li>
            <li><a href="#enf">Enfermagem</a></li>
            <li><a href="#eng">Engenharia Ambiental</a></li>
            <li><a href="#geo">Geografia</a></li>
            <li><a href="#his">História</a></li>
            <li><a href="#letras">Letras</a></li>
            <li><a href="#mat">Matemática</a></li>   
            <li><a href="#med">Medicina</a></li>
            <li><a href="#ped">Pedagogia</a></li>
          </ul>
        </nav>
      </div>

      <Cc/>    
    </div>
    
  );
}

export default App;