import React from "react";
import axios from "axios";
import BasicButtons from "./BasicButtons";
//import Cc from "./Cc";
import Header from "./Header";

axios.defaults.baseURL = "http://localhost:3010/";
axios.defaults.headers.common["Content-Type"] = "application/json;charset=utf-8";

function App( ) {

  return (
  <div>
    <Header/>
    <h1 class="h1-cursos">Cursos:</h1>
  
    <div class="col d-flex justify-content-center">
      <nav>
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
        </ul>
      </nav>
    </div>
     
  </div>
  );
}

export default App;