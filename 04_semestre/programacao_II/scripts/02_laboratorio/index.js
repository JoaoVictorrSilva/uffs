const express = require('express');
const app = express();
const bodyParser = require('body-parser');
app.use(bodyParser.json());
app.listen(3000, () => console.log('Servidor Rodando...'));

const db = require('./database');
const indice = require('./indiceCurso');

app.get('/Curso', (request, response) => {
  response.json(db.cursos);
})

app.post('/Curso', (request, response) => {
  //Informações curso:
  const nome = request.body.nome;
  const id = request.body.id;
  const turno = request.body.turno;
  const id_campus = request.body.id_campus;
  
  //Inserindo no vetor o curso:
  db.cursos.push({
    id: parseInt(id),
    nome: nome,
    turno: parseInt(turno),
    id_campus: parseInt(id_campus)
  })

  response.json({Mensagem: 'Curso Cadastrado!'});
})

app.put('/Curso', (request, response) => {
  for(let i = 0; i < db.cursos.length; i++){
    if(db.cursos[i].id == request.body.id){
      db.cursos[i].id_campus = request.body.id_campus;
      db.cursos[i].nome = request.body.nome;
      db.cursos[i].turno = request.body.turno;
    }
  }

  response.json({Mensagem: 'Curso Atualizado!'});
})

app.delete('/Curso', (request, response) => {
  for(let i = 0; i < db.cursos.length; i++){
    if(db.cursos[i].id == request.body.id){
      db.cursos.splice(i, 1);
    }
  }

  response.json({Mensagem: 'Curso Deletado!'});
})

app.get('/Ccrs', (request, response) => {
  response.json(db.ccrs);
})

app.post('/Ccrs', (request, response) => {
  //Informações curso:
  const nome = request.body.nome;
  const id = request.body.id;
  
  //Inserindo no vetor o curso:
  db.cursos.push({
    id: parseInt(id),
    nome: nome
  })

  response.json({Mensagem: 'Ccr Cadastrado!'});
})

app.put('/Ccrs', (request, response) => {
  for(let i = 0; i < db.ccrs.length; i++){
    if(db.ccrs[i].id == request.body.id){
      db.ccrs[i].nome = request.body.nome;
    }
  }

  response.json({Mensagem: 'Ccr Atualizado!'});
})

app.delete('/Ccrs', (request, response) => {
  for(let i = 0; i < db.ccrs.length; i++){
    if(db.ccrs[i].id == request.body.id){
      db.ccrs.splice(i, 1);
    }
  }

  response.json({Mensagem: 'Ccr Deletado!'});
})