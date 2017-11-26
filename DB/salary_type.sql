INSERT INTO "OrmasSchema".salary_type(
            salary_type_id, salary_type_code, salary_type_name)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'FIXED', 'Fixed salary');
INSERT INTO "OrmasSchema".salary_type(
            salary_type_id, salary_type_code, salary_type_name)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'PERCENT', 'Percent salary');
INSERT INTO "OrmasSchema".salary_type(
            salary_type_id, salary_type_code, salary_type_name)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'HOURLY', 'Hourly rate salary');
INSERT INTO "OrmasSchema".salary_type(
            salary_type_id, salary_type_code, salary_type_name)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'SHIFT', 'Shift salary');
INSERT INTO "OrmasSchema".salary_type(
            salary_type_id, salary_type_code, salary_type_name)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'PIECE', 'Piece salary');