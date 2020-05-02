INSERT INTO "OrmasSchema".amortize_type(
            amortize_type_id, amortize_type_name, amortize_type_code)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'STRAIGHT-LINE', 'Straight-line amortization');
INSERT INTO "OrmasSchema".amortize_type(
            amortize_type_id, amortize_type_name, amortize_type_code)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'REDUCING', 'Reduce depreciation amortization');
INSERT INTO "OrmasSchema".amortize_type(
            amortize_type_id, amortize_type_name, amortize_type_code)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'WRITE-OFF', 'Write off the value of the sum');
INSERT INTO "OrmasSchema".amortize_type(
            amortize_type_id, amortize_type_name, amortize_type_code)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'PROPORTION', 'Writing off the value in proportion');