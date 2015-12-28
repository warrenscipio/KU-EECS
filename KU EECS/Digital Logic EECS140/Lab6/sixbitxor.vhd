----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:00:50 03/14/2013 
-- Design Name: 
-- Module Name:    sixbitxor - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

---- Uncomment the following library declaration if instantiating
---- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity sixbitxor is

PORT (
 U,V,W,X,Y,Z: IN STD_LOGIC;
 I : OUT STD_LOGIC);

end sixbitxor;

ARCHITECTURE Structural of sixbitxor IS

-- Component Declaration
 COMPONENT twobitxor IS
 PORT (
 A,B : IN STD_LOGIC;
 G : OUT STD_LOGIC);
 
 END COMPONENT twobitxor;

COMPONENT threebitxor IS
 PORT (
 A,B,C : IN STD_LOGIC;
 H : OUT STD_LOGIC);
 
 END COMPONENT threebitxor;
 
 -- Signal Declaration
 SIGNAL UxorVxorW: STD_LOGIC;
 SIGNAL XxorYxorZ: STD_LOGIC;




begin


-- Component Instantiation
 UVW: threebitxor
 PORT MAP (
A => U,
B => V,
C => W,
H => UxorVxorW);

 XYZ: threebitxor
 PORT MAP (
A => X,
B => Y,
C => Z,
H => XxorYxorZ);

UVWXYZ: twobitxor
 PORT MAP (
A => UxorVxorW,
B => XxorYxorZ,
G => I);
END ARCHITECTURE Structural;

