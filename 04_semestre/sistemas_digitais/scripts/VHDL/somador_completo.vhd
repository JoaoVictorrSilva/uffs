entity somador_completo is
  port(
    A, B  : in bit;
    TE    : in bit; -- carry -> transporte de entrada
    S     : out bit; -- soma
    TS    : out bit -- transporte de saída
  );
end entity somador_completo;

architecture main of somador_completo is
  
  begin
    S <= A xor B xor TE;
    TS <= (A and B) or (A and TE) or (B and TE);

end architecture main;