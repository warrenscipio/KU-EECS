VERSION 6
BEGIN SCHEMATIC
    BEGIN ATTR DeviceFamilyName "spartan3e"
        DELETE all:0
        EDITNAME all:0
        EDITTRAIT all:0
    END ATTR
    BEGIN NETLIST
        SIGNAL XLXN_1
        SIGNAL XLXN_2
        SIGNAL XLXN_3
        SIGNAL XLXN_4
        BEGIN SIGNAL XLXN_5
        END SIGNAL
        SIGNAL XLXN_7
        SIGNAL XLXN_9
        BEGIN SIGNAL XLXN_12
        END SIGNAL
        SIGNAL XLXN_13
        SIGNAL XLXN_18
        SIGNAL XLXN_20
        SIGNAL XLXN_21
        SIGNAL XLXN_22
        SIGNAL XLXN_24
        PORT Input XLXN_24
        BEGIN BLOCKDEF and2
            TIMESTAMP 2000 1 1 10 10 10
            LINE N 0 -64 64 -64 
            LINE N 0 -128 64 -128 
            LINE N 256 -96 192 -96 
            ARC N 96 -144 192 -48 144 -48 144 -144 
            LINE N 144 -48 64 -48 
            LINE N 64 -144 144 -144 
            LINE N 64 -48 64 -144 
        END BLOCKDEF
        BEGIN BLOCKDEF or3
            TIMESTAMP 2000 1 1 10 10 10
            LINE N 0 -64 48 -64 
            LINE N 0 -128 72 -128 
            LINE N 0 -192 48 -192 
            LINE N 256 -128 192 -128 
            ARC N 28 -256 204 -80 112 -80 192 -128 
            ARC N -40 -184 72 -72 48 -80 48 -176 
            LINE N 48 -64 48 -80 
            LINE N 48 -192 48 -176 
            LINE N 112 -80 48 -80 
            ARC N 28 -176 204 0 192 -128 112 -176 
            LINE N 112 -176 48 -176 
        END BLOCKDEF
        BEGIN BLOCKDEF inv
            TIMESTAMP 2000 1 1 10 10 10
            LINE N 0 -32 64 -32 
            LINE N 224 -32 160 -32 
            LINE N 64 -64 128 -32 
            LINE N 128 -32 64 0 
            LINE N 64 0 64 -64 
            CIRCLE N 128 -48 160 -16 
        END BLOCKDEF
        BEGIN BLOCK XLXI_1 and2
            PIN I0 XLXN_7
            PIN I1 XLXN_24
            PIN O XLXN_1
        END BLOCK
        BEGIN BLOCK XLXI_2 and2
            PIN I0 XLXN_12
            PIN I1 XLXN_9
            PIN O XLXN_2
        END BLOCK
        BEGIN BLOCK XLXI_3 and2
            PIN I0 XLXN_4
            PIN I1 XLXN_13
            PIN O XLXN_3
        END BLOCK
        BEGIN BLOCK XLXI_4 or3
            PIN I0 XLXN_3
            PIN I1 XLXN_2
            PIN I2 XLXN_1
            PIN O
        END BLOCK
        BEGIN BLOCK XLXI_5 inv
            PIN I XLXN_24
            PIN O XLXN_24
        END BLOCK
    END NETLIST
    BEGIN SHEET 1 3520 2720
        INSTANCE XLXI_1 992 928 R0
        INSTANCE XLXI_2 992 1136 R0
        INSTANCE XLXI_3 1008 1360 R0
        INSTANCE XLXI_4 1536 1152 R0
        BEGIN BRANCH XLXN_1
            WIRE 1248 832 1536 832
            WIRE 1536 832 1536 960
        END BRANCH
        BEGIN BRANCH XLXN_2
            WIRE 1248 1040 1392 1040
            WIRE 1392 1024 1392 1040
            WIRE 1392 1024 1536 1024
        END BRANCH
        BEGIN BRANCH XLXN_3
            WIRE 1264 1264 1536 1264
            WIRE 1536 1088 1536 1264
        END BRANCH
        BEGIN BRANCH XLXN_4
            WIRE 800 1296 1008 1296
        END BRANCH
        BEGIN BRANCH XLXN_7
            WIRE 784 864 976 864
            WIRE 976 864 992 864
        END BRANCH
        BEGIN BRANCH XLXN_9
            WIRE 784 1008 992 1008
        END BRANCH
        BEGIN BRANCH XLXN_12
            WIRE 784 1072 992 1072
        END BRANCH
        BEGIN BRANCH XLXN_13
            WIRE 800 1232 1008 1232
        END BRANCH
        IOMARKER 336 816 XLXN_24 R180 28
        BEGIN BRANCH XLXN_24
            WIRE 336 816 432 816
            WIRE 432 704 432 816
            WIRE 432 704 528 704
            WIRE 528 704 752 704
            WIRE 752 704 992 704
            WIRE 992 704 992 736
            WIRE 912 592 912 736
            WIRE 912 736 992 736
            WIRE 912 592 1008 592
            WIRE 1008 592 1008 720
            WIRE 928 720 928 800
            WIRE 928 800 992 800
            WIRE 928 720 1008 720
        END BRANCH
        INSTANCE XLXI_5 528 736 R0
    END SHEET
END SCHEMATIC
