entity somador4 is
  port(
    a, b  : in integer range 0 to 15; --integer -> inteiro; range 0 to 15 (4 bits);
    z     : out integer range 0 to 15 
  );
end entity somador4;

architecture main of somador4 is
begin

  z <= a + b;

end architecture main; -- somador