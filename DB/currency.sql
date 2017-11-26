--------------------------------------Currency-----------------------------------------------------------

INSERT INTO "OrmasSchema".currencies(
            currency_id, currency_code, currency_short_name, currency_name, 
            currency_unit, currency_main_trade)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 800, 'RUB', 'Russian Ruble', 100, false);
INSERT INTO "OrmasSchema".currencies(
            currency_id, currency_code, currency_short_name, currency_name, 
            currency_unit, currency_main_trade)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 840, 'USD', 'United States Dollar', 100, false);
INSERT INTO "OrmasSchema".currencies(
            currency_id, currency_code, currency_short_name, currency_name, 
            currency_unit, currency_main_trade)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 790, 'TJS', 'Somoni', 100, true);