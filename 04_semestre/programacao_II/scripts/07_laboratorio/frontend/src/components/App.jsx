import React from "react";
import BasicButtons from "./BasicButtons";
import Header from "./Header";
import ButtonFollow from "./ButtonFollow";
import Cc from "./Cc";

function App( ) {

  return (
  <div>
    <Header/>
    <h1 class="h1-cursos">Cursos:</h1>
  
    <div class="col d-flex justify-content-center">
      <ul>
        <BasicButtons curso="Administração"/>
        <BasicButtons curso="Agronomia"/>
        <BasicButtons curso="Ciências da Computação"/>
        <BasicButtons curso="Enfermagem"/>
        <BasicButtons curso="Engenharia Ambiental"/>
        <BasicButtons curso="Geografia"/>
        <BasicButtons curso="História"/>
        <BasicButtons curso="Letras"/>
        <BasicButtons curso="Matemática"/>
        <BasicButtons curso="Medicina"/>
        <BasicButtons curso="Pedagogia"/>
        <ButtonFollow/>
      </ul>
    </div>

    <br/>
    <br/>
    <Cc titulo={"Ciências da Computação"}/>

  </div>
  );
}

export default App;