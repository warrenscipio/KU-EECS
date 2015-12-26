-- A gated RS latch described the hard way
LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY gatedDlatch IS
    PORT ( Clk, D : IN STD_LOGIC;
           Q         : OUT STD_LOGIC);
END gatedDlatch ;

ARCHITECTURE Structural OF gatedDlatch IS
  SIGNAL R_g, S_g, Qa, Qb : STD_LOGIC ;
  ATTRIBUTE keep : boolean;
  ATTRIBUTE keep of R_g, S_g, Qa, Qb : SIGNAL IS true;
BEGIN

  R_g <= D NAND Clk;
  S_g <= (NOT D) NAND Clk;
  Qa <= NOT (R_g AND Qb);
  Qb <= NOT (S_g AND Qa);
  Q <= Qa;
  
END Structural;