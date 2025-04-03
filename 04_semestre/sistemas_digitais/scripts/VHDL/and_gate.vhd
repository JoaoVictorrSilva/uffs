-- Bibliotecas e pacotes

-- Entidade
entity and_gate is
  port(
    a, b  : in bit; -- a, b entradas (in);
    z     : out bit -- z saída (out);
  );
end entity and_gate;

-- Arquitetura
architecture main of and_gate is -- uma arquitetura com nome maon para a entidade and_gate
begin -- para iniciar o código
  
  z <= a and b; -- z recebe a and b;
  
end architecture main;