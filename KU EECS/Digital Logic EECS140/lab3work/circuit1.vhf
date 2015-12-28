--------------------------------------------------------------------------------
-- Copyright (c) 1995-2007 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 9.2i
--  \   \         Application : sch2vhdl
--  /   /         Filename : circuit1.vhf
-- /___/   /\     Timestamp : 02/14/2013 10:07:16
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: C:\Xilinx92i\bin\nt\sch2vhdl.exe -intstyle ise -family spartan3e -flat -suppress -w H:/EECS140/lab3work/circuit1.sch circuit1.vhf
--Design Name: circuit1
--Device: spartan3e
--Purpose:
--    This vhdl netlist is translated from an ECS schematic. It can be 
--    synthesis and simulted, but it should not be modified. 
--

library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity circuit1 is
   port ( A : in    std_logic; 
          B : in    std_logic; 
          C : in    std_logic; 
          Y : out   std_logic);
end circuit1;

architecture BEHAVIORAL of circuit1 is
   attribute BOX_TYPE   : string ;
   signal XLXN_7  : std_logic;
   signal XLXN_8  : std_logic;
   signal XLXN_10 : std_logic;
   signal XLXN_12 : std_logic;
   signal XLXN_13 : std_logic;
   signal XLXN_14 : std_logic;
   component INV
      port ( I : in    std_logic; 
             O : out   std_logic);
   end component;
   attribute BOX_TYPE of INV : component is "BLACK_BOX";
   
   component AND2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND2 : component is "BLACK_BOX";
   
   component OR3
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of OR3 : component is "BLACK_BOX";
   
begin
   XLXI_1 : INV
      port map (I=>A,
                O=>XLXN_7);
   
   XLXI_2 : INV
      port map (I=>B,
                O=>XLXN_8);
   
   XLXI_3 : INV
      port map (I=>C,
                O=>XLXN_10);
   
   XLXI_5 : AND2
      port map (I0=>XLXN_8,
                I1=>XLXN_7,
                O=>XLXN_14);
   
   XLXI_6 : AND2
      port map (I0=>XLXN_10,
                I1=>B,
                O=>XLXN_13);
   
   XLXI_7 : AND2
      port map (I0=>XLXN_8,
                I1=>C,
                O=>XLXN_12);
   
   XLXI_8 : OR3
      port map (I0=>XLXN_12,
                I1=>XLXN_13,
                I2=>XLXN_14,
                O=>Y);
   
end BEHAVIORAL;


