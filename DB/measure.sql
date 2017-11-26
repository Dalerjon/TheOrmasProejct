------------------------------------Measure--------------------------------------------------------------------------

INSERT INTO "OrmasSchema".measures(
            measure_id, measure_name, measure_short_name, measure_unit)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'Тонна', 'т', 1000);
INSERT INTO "OrmasSchema".measures(
            measure_id, measure_name, measure_short_name, measure_unit)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'Киллограмм', 'кг', 1000);
INSERT INTO "OrmasSchema".measures(
            measure_id, measure_name, measure_short_name, measure_unit)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'Грамм', 'гр', 1);
INSERT INTO "OrmasSchema".measures(
            measure_id, measure_name, measure_short_name, measure_unit)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'Литр', 'л', 1000);
INSERT INTO "OrmasSchema".measures(
            measure_id, measure_name, measure_short_name, measure_unit)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'Миллилитр', 'мл', 1);
