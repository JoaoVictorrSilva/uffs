-- create database homework;

-- Tabelas:

create table curso(
  codc integer not null,
  nome varchar(30) not null,
  constraint pk_codc primary key (codc)
);

create table aluno(
  matr integer not null,
  nome varchar(30) not null,
  cpf varchar(11) not null,
  ender varchar(50) not null,
  email varchar(30) not null,
  codc integer not null,
  constraint pk_matr primary key (matr),
  constraint fk_codc foreign key (codc) references curso(codc)
);

create table ccr(
  codccr integer not null,
  sigla varchar(10) not null,
  nome varchar(30) not null,
  cred integer not null,
  codc integer not null,
  constraint pk_codccr primary key (codccr),
  constraint fk_codc foreign key (codc) references curso(codc)
);

create table historico(
  matr integer not null,
  codccr integer not null,
  semestre varchar(10) not null,
  ppres integer not null,
  media numeric(4,2) not null,
  constraint pk_historico primary key (matr, codccr, semestre),
  constraint fk_matr foreign key (matr) references aluno(matr),
  constraint fk_codccr foreign key (codccr) references ccr(codccr)
);

-- Inserções tabelas:

-- cursos:
insert into curso (codc, nome) 
values 
(1, 'Ciência da Computação'), 
(3, 'Enfermagem'), 
(2, 'Administração'), 
(4, 'Filosofia');

-- ccrs:
insert into ccr (codccr, sigla, nome, cred, codc) values
(8, 'BD I', 'Banco de Dados I', 4, 1),
(7, 'BD II', 'Banco de Dados II', 4, 1),
(4, 'CH I', 'Corpo Humano I', 3, 3),
(5, 'EP I', 'Epistemologia', 2, 4);

-- alunos:
insert into aluno (matr, nome, cpf, ender, email, codc) values
(2023, 'João Victor da Silva', '10430734925', 'Eleven Street', 'joao.vt2807@gmail.com', 1),
(2018,'Sra Um','01010101','Rua Um','um@uffs',1),
(2017,'Tre','03030303','Tre Gatan','tre@uffs',2),
(2011,'Huit','08080808','Rue Huit','huit@uffs',3);

insert into historico (matr,codccr,semestre,ppres,media) values 
(2017,8,'19-2',78,5.4),
(2018,7,'19-2',81,7.6),
(2023,4,'19-2',95,8.6),
(2011,5,'20-1',88,6.0);