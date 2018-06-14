--------------------------------------Currency-----------------------------------------------------------
INSERT INTO "OrmasSchema".currencies(
            currency_id, currency_code, currency_short_name, currency_name, 
            currency_unit, currency_main_trade)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 790, 'TJS', 'Сомони', 100, true);
INSERT INTO "OrmasSchema".currencies(
            currency_id, currency_code, currency_short_name, currency_name, 
            currency_unit, currency_main_trade)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 800, 'RUB', 'Рубль', 100, false);
INSERT INTO "OrmasSchema".currencies(
            currency_id, currency_code, currency_short_name, currency_name, 
            currency_unit, currency_main_trade)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 840, 'USD', 'Доллары', 100, false);
