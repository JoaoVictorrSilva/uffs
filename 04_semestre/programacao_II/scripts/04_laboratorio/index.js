const express = require('express');
const app = express();
const bodyParser = require('body-parser');
const database = require('./database');
app.use(bodyParser.json());
app.listen(3001, () => console.log('Servidor rodando na porta 3001'));

app.get('/', (request, response) => {
  response.sendFile(`${__dirname}/public/index.html`);
})

// CURSOS:
app.get('/Curso', (request, response) => {
  response.json(database.cursos);
})

app.post('/Curso', (request, response) => {
  const id = request.body.id;
  const nome = request.body.nome;
  const turno = request.body.turno;
  const id_campus = request.body.id_campus;

  database.cursos.push({
    id: parseInt(id),
    nome: nome,
    turno: parseInt(turno),
    id_campus: parseInt(id_campus)
  })

  response.json({Mensagem: 'Curso Cadastrado!'});
})

app.put('/Curso', (request, response) => {
  for(let i = 0; i < database.cursos.length; i++){
    if(database.cursos[i].id == request.body.id){
      database.cursos[i].nome = request.body.nome;
      database.cursos[i].turno = request.body.turno;
      database.cursos[i].id_campus = request.body.id_campus;

      response.json({Mensagem: 'Curso atualizado!'});
      break;
    }
  }
  response.json({Mensagem: 'Curso não encontrado!'});
})

app.delete('/Curso', (request, response) => {
  for(let i = 0; i < database.cursos.length; i++){
    if(database.cursos[i].id == request.body.id){
      database.cursos.splice(i, 1);
      response.json({Mensagem: 'Curso deletado!'});
      break;
    }
  }
  response.json({Mensagem: 'Curso não encontrado!'});
})


// CCRS:
app.get('/Ccrs', (request, response) => {
  response.json(database.ccrs);
})

app.post('/Ccrs', (request, response) => {
  const id = request.body.id;
  const nome = request.body.nome;

  database.ccrs.push({
    id: parseInt(id),
    nome: nome,
  })

  response.json({Mensagem: 'Ccr Cadastrado!'});
})

app.put('/Ccr', (request, response) => {
  for(let i = 0; i < database.ccrs.length; i++){
    if(database.ccrs[i].id == request.body.id){
      database.ccrs[i].nome = request.body.nome;
      response.json({Mensagem: 'Ccr atualizado!'});
      break;
    }
  }
  response.json({Mensagem: 'Ccr não encontrado!'});
})

app.delete('/Ccr', (request, response) => {
  for(let i = 0; i < database.ccrs.length; i++){
    if(database.ccrs[i].id == request.body.id){
      database.ccrs.splice(i, 1);
      response.json({Mensagem: 'Ccr deletado!'});
      break;
    }
  }
  response.json({Mensagem: 'Ccr não encontrado!'});
})