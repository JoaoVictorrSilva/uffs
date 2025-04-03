const express = require('express');
const app = express();
const bodyParser = require('body-parser');

app.use(bodyParser.json());
app.use(express.static('public'));
app.listen(3001, () => console.log('Servidor Rodando...'));

app.get('/', (request, response) => {
  response.sendFile(`${__dirname}/index.html`);
})