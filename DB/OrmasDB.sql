--
-- PostgreSQL database dump
--

-- Dumped from database version 9.5.16
-- Dumped by pg_dump version 9.5.4

-- Started on 2020-05-02 14:03:07

SET statement_timeout = 0;
SET lock_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SET check_function_bodies = false;
SET client_min_messages = warning;
SET row_security = off;

--
-- TOC entry 7 (class 2615 OID 20742)
-- Name: OrmasSchema; Type: SCHEMA; Schema: -; Owner: postgres
--

CREATE SCHEMA "OrmasSchema";


ALTER SCHEMA "OrmasSchema" OWNER TO postgres;

--
-- TOC entry 3478 (class 0 OID 0)
-- Dependencies: 7
-- Name: SCHEMA "OrmasSchema"; Type: COMMENT; Schema: -; Owner: postgres
--

COMMENT ON SCHEMA "OrmasSchema" IS 'Ormas application schema';


--
-- TOC entry 1 (class 3079 OID 12355)
-- Name: plpgsql; Type: EXTENSION; Schema: -; Owner: 
--

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;


--
-- TOC entry 3482 (class 0 OID 0)
-- Dependencies: 1
-- Name: EXTENSION plpgsql; Type: COMMENT; Schema: -; Owner: 
--

COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';


SET search_path = "OrmasSchema", pg_catalog;

--
-- TOC entry 434 (class 1255 OID 20743)
-- Name: getcurrentdate(); Type: FUNCTION; Schema: OrmasSchema; Owner: postgres
--

CREATE FUNCTION getcurrentdate() RETURNS text
    LANGUAGE plpgsql IMMUTABLE
    AS $$
DECLARE 
    currentdate text;
BEGIN
 currentdate := to_char(now()::timestamp(0), 'dd.MM.yyyy hh24:mm');
 return currentdate;
END;
$$;


ALTER FUNCTION "OrmasSchema".getcurrentdate() OWNER TO postgres;

--
-- TOC entry 182 (class 1259 OID 20744)
-- Name: acc_seq; Type: SEQUENCE; Schema: OrmasSchema; Owner: postgres
--

CREATE SEQUENCE acc_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    MAXVALUE 999999999
    CACHE 1;


ALTER TABLE acc_seq OWNER TO postgres;

SET default_tablespace = '';

SET default_with_oids = false;

--
-- TOC entry 183 (class 1259 OID 20746)
-- Name: access_items; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE access_items (
    access_item_id integer NOT NULL,
    access_item_eng character varying(30) NOT NULL,
    access_item_ru character varying(30) NOT NULL,
    access_division character varying(20) NOT NULL
);


ALTER TABLE access_items OWNER TO postgres;

--
-- TOC entry 184 (class 1259 OID 20749)
-- Name: access_items_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW access_items_view AS
 SELECT access_items.access_item_id,
    access_items.access_item_eng,
    access_items.access_item_ru AS access_iterm_ru,
    access_items.access_division
   FROM access_items;


ALTER TABLE access_items_view OWNER TO postgres;

--
-- TOC entry 185 (class 1259 OID 20753)
-- Name: accesses; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE accesses (
    access_id integer NOT NULL,
    role_id integer NOT NULL,
    access_item_id integer NOT NULL
);


ALTER TABLE accesses OWNER TO postgres;

--
-- TOC entry 186 (class 1259 OID 20756)
-- Name: roles; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE roles (
    role_id integer NOT NULL,
    role_code character varying(20) NOT NULL,
    role_name character varying(50) NOT NULL,
    comment character varying(100)
);


ALTER TABLE roles OWNER TO postgres;

--
-- TOC entry 187 (class 1259 OID 20759)
-- Name: accesses_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW accesses_view AS
 SELECT accesses.access_id,
    r.role_name,
    a.access_item_eng,
    a.access_item_ru,
    a.access_division,
    accesses.role_id,
    accesses.access_item_id
   FROM ((accesses
     JOIN roles r ON ((r.role_id = accesses.role_id)))
     JOIN access_items a ON ((a.access_item_id = accesses.access_item_id)));


ALTER TABLE accesses_view OWNER TO postgres;

--
-- TOC entry 188 (class 1259 OID 20763)
-- Name: account_history; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE account_history (
    account_history_id integer NOT NULL,
    account_id integer NOT NULL,
    account_number character varying(20) NOT NULL,
    start_balance numeric(20,3),
    current_balance numeric(20,3),
    from_date date,
    till_date date
);


ALTER TABLE account_history OWNER TO postgres;

--
-- TOC entry 189 (class 1259 OID 20766)
-- Name: account_history_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW account_history_view AS
 SELECT account_history.account_history_id,
    account_history.account_id,
    account_history.account_number,
    account_history.start_balance,
    account_history.current_balance,
    account_history.from_date,
    account_history.till_date
   FROM account_history;


ALTER TABLE account_history_view OWNER TO postgres;

--
-- TOC entry 190 (class 1259 OID 20770)
-- Name: account_type; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE account_type (
    account_type_id integer NOT NULL,
    account_type_name character varying(50) NOT NULL,
    account_type_number integer NOT NULL,
    comment character varying(100)
);


ALTER TABLE account_type OWNER TO postgres;

--
-- TOC entry 191 (class 1259 OID 20773)
-- Name: account_type_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW account_type_view AS
 SELECT account_type.account_type_id,
    account_type.account_type_name,
    account_type.account_type_number,
    account_type.comment
   FROM account_type;


ALTER TABLE account_type_view OWNER TO postgres;

--
-- TOC entry 192 (class 1259 OID 20777)
-- Name: accountable; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE accountable (
    employee_id integer NOT NULL,
    information character varying(200)
);


ALTER TABLE accountable OWNER TO postgres;

--
-- TOC entry 193 (class 1259 OID 20780)
-- Name: accountable_transaction; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE accountable_transaction (
    accountable_transaction_id integer NOT NULL,
    accountable_id integer NOT NULL,
    start_value numeric(20,3),
    end_value numeric(20,3),
    operation_id integer NOT NULL
);


ALTER TABLE accountable_transaction OWNER TO postgres;

--
-- TOC entry 194 (class 1259 OID 20783)
-- Name: accountable_transaction_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW accountable_transaction_view AS
 SELECT accountable_transaction.accountable_transaction_id,
    accountable_transaction.accountable_id,
    accountable_transaction.start_value,
    accountable_transaction.end_value,
    accountable_transaction.operation_id
   FROM accountable_transaction;


ALTER TABLE accountable_transaction_view OWNER TO postgres;

--
-- TOC entry 195 (class 1259 OID 20787)
-- Name: users; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE users (
    user_id integer NOT NULL,
    user_email character varying(30) NOT NULL,
    user_name character varying(40) NOT NULL,
    user_surname character varying(50),
    user_phone character varying(20),
    user_address character varying(50),
    role_id integer NOT NULL,
    password character varying(30),
    activated boolean
);


ALTER TABLE users OWNER TO postgres;

--
-- TOC entry 196 (class 1259 OID 20790)
-- Name: accountable_veiw; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW accountable_veiw AS
 SELECT users.user_id,
    users.user_name,
    users.user_surname,
    accountable.information,
    users.user_phone,
    users.user_address,
    ( SELECT roles.role_name
           FROM roles
          WHERE (roles.role_id = users.role_id)) AS role_name
   FROM (accountable
     JOIN users ON ((users.user_id = accountable.employee_id)));


ALTER TABLE accountable_veiw OWNER TO postgres;

--
-- TOC entry 197 (class 1259 OID 20794)
-- Name: accounts; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE accounts (
    account_id integer NOT NULL,
    account_number character varying(20) NOT NULL,
    start_balance numeric(20,3) NOT NULL,
    current_balance numeric(20,3) NOT NULL
);


ALTER TABLE accounts OWNER TO postgres;

--
-- TOC entry 198 (class 1259 OID 20797)
-- Name: accounts_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW accounts_view AS
 SELECT accounts.account_id,
    accounts.account_number,
    accounts.start_balance,
    accounts.current_balance
   FROM accounts;


ALTER TABLE accounts_view OWNER TO postgres;

--
-- TOC entry 199 (class 1259 OID 20801)
-- Name: amortize_group; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE amortize_group (
    amortize_group_id integer NOT NULL,
    group_number integer,
    from_month integer,
    to_month integer
);


ALTER TABLE amortize_group OWNER TO postgres;

--
-- TOC entry 200 (class 1259 OID 20804)
-- Name: amortize_group_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW amortize_group_view AS
 SELECT amortize_group.amortize_group_id,
    amortize_group.group_number,
    amortize_group.from_month,
    amortize_group.to_month
   FROM amortize_group;


ALTER TABLE amortize_group_view OWNER TO postgres;

--
-- TOC entry 201 (class 1259 OID 20808)
-- Name: amortize_type; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE amortize_type (
    amortize_type_id integer NOT NULL,
    amortize_type_name character varying(100),
    amortize_type_code character varying(50)
);


ALTER TABLE amortize_type OWNER TO postgres;

--
-- TOC entry 202 (class 1259 OID 20811)
-- Name: amortize_type_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW amortize_type_view AS
 SELECT amortize_type.amortize_type_id,
    amortize_type.amortize_type_name,
    amortize_type.amortize_type_code
   FROM amortize_type;


ALTER TABLE amortize_type_view OWNER TO postgres;

--
-- TOC entry 203 (class 1259 OID 20815)
-- Name: balance_payment; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE balance_payment (
    balance_payment_id integer NOT NULL,
    balance_id integer NOT NULL,
    payment_id integer NOT NULL
);


ALTER TABLE balance_payment OWNER TO postgres;

--
-- TOC entry 204 (class 1259 OID 20818)
-- Name: balance_payment_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW balance_payment_view AS
 SELECT balance_payment.balance_payment_id,
    balance_payment.balance_id,
    balance_payment.payment_id
   FROM balance_payment;


ALTER TABLE balance_payment_view OWNER TO postgres;

--
-- TOC entry 205 (class 1259 OID 20822)
-- Name: balance_payslip; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE balance_payslip (
    balance_payslip_id integer NOT NULL,
    balance_id integer NOT NULL,
    payslip_id integer NOT NULL
);


ALTER TABLE balance_payslip OWNER TO postgres;

--
-- TOC entry 206 (class 1259 OID 20825)
-- Name: balance_payslip_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW balance_payslip_view AS
 SELECT balance_payslip.balance_payslip_id,
    balance_payslip.balance_id,
    balance_payslip.payslip_id
   FROM balance_payslip;


ALTER TABLE balance_payslip_view OWNER TO postgres;

--
-- TOC entry 207 (class 1259 OID 20829)
-- Name: balance_refund; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE balance_refund (
    balance_refund_id integer NOT NULL,
    balance_id integer NOT NULL,
    refund_id integer NOT NULL
);


ALTER TABLE balance_refund OWNER TO postgres;

--
-- TOC entry 208 (class 1259 OID 20832)
-- Name: balance_refund_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW balance_refund_view AS
 SELECT balance_refund.balance_refund_id,
    balance_refund.balance_id,
    balance_refund.refund_id
   FROM balance_refund;


ALTER TABLE balance_refund_view OWNER TO postgres;

--
-- TOC entry 209 (class 1259 OID 20836)
-- Name: balance_withdrawal; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE balance_withdrawal (
    balance_withdrawal_id integer NOT NULL,
    balance_id integer NOT NULL,
    withdrawal_id integer NOT NULL
);


ALTER TABLE balance_withdrawal OWNER TO postgres;

--
-- TOC entry 210 (class 1259 OID 20839)
-- Name: balance_withdrawal_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW balance_withdrawal_view AS
 SELECT balance_withdrawal.balance_withdrawal_id,
    balance_withdrawal.balance_id,
    balance_withdrawal.withdrawal_id
   FROM balance_withdrawal;


ALTER TABLE balance_withdrawal_view OWNER TO postgres;

--
-- TOC entry 211 (class 1259 OID 20843)
-- Name: balances; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE balances (
    balance_id integer NOT NULL,
    user_id integer NOT NULL,
    subaccount_id integer NOT NULL
);


ALTER TABLE balances OWNER TO postgres;

--
-- TOC entry 212 (class 1259 OID 20846)
-- Name: currencies; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE currencies (
    currency_id integer NOT NULL,
    currency_code integer,
    currency_short_name character varying(3),
    currency_name character varying(20),
    currency_unit integer NOT NULL,
    currency_main_trade boolean
);


ALTER TABLE currencies OWNER TO postgres;

--
-- TOC entry 213 (class 1259 OID 20849)
-- Name: subaccounts; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE subaccounts (
    subaccount_id integer NOT NULL,
    account_id integer NOT NULL,
    subaccount_number character varying(20) NOT NULL,
    start_balance numeric(20,3) NOT NULL,
    current_balance numeric(20,3) NOT NULL,
    currency_id integer NOT NULL,
    status_id integer NOT NULL,
    date_opened date NOT NULL,
    date_closed date,
    details character varying(100)
);


ALTER TABLE subaccounts OWNER TO postgres;

--
-- TOC entry 214 (class 1259 OID 20852)
-- Name: balances_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW balances_view AS
 SELECT balances.balance_id,
    u.user_name,
    u.user_surname,
    s.subaccount_number,
    s.current_balance,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = s.currency_id)) AS currency_name,
    balances.user_id,
    balances.subaccount_id
   FROM ((balances
     JOIN users u ON ((u.user_id = balances.user_id)))
     JOIN subaccounts s ON ((s.subaccount_id = balances.subaccount_id)));


ALTER TABLE balances_view OWNER TO postgres;

--
-- TOC entry 215 (class 1259 OID 20857)
-- Name: borrowers; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE borrowers (
    user_id integer NOT NULL,
    comment character varying(200)
);


ALTER TABLE borrowers OWNER TO postgres;

--
-- TOC entry 216 (class 1259 OID 20860)
-- Name: borrowers_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW borrowers_view AS
 SELECT users.user_id,
    users.user_name,
    users.user_surname,
    borrowers.comment,
    users.user_phone,
    users.user_address,
    ( SELECT roles.role_name
           FROM roles
          WHERE (roles.role_id = users.role_id)) AS role_name,
    users.password,
    users.user_email,
    users.activated,
    users.role_id
   FROM (borrowers
     JOIN users ON ((users.user_id = borrowers.user_id)));


ALTER TABLE borrowers_view OWNER TO postgres;

--
-- TOC entry 217 (class 1259 OID 20865)
-- Name: branches; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE branches (
    branch_id integer NOT NULL,
    branch_name character varying(60) NOT NULL,
    branch_address character varying(60) NOT NULL,
    branch_phone character varying(15) NOT NULL,
    commnet character varying(100)
);


ALTER TABLE branches OWNER TO postgres;

--
-- TOC entry 218 (class 1259 OID 20868)
-- Name: branches_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW branches_view AS
 SELECT branches.branch_id,
    branches.branch_name,
    branches.branch_address,
    branches.branch_phone,
    branches.commnet
   FROM branches;


ALTER TABLE branches_view OWNER TO postgres;

--
-- TOC entry 219 (class 1259 OID 20872)
-- Name: cashbox; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE cashbox (
    cashbox_id integer NOT NULL,
    subaccount_id integer NOT NULL,
    information character varying(60),
    cashbox_address character varying(60)
);


ALTER TABLE cashbox OWNER TO postgres;

--
-- TOC entry 220 (class 1259 OID 20875)
-- Name: cashbox_employee; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE cashbox_employee (
    cashbox_employee_id integer NOT NULL,
    cashbox_id integer NOT NULL,
    employee_id integer NOT NULL
);


ALTER TABLE cashbox_employee OWNER TO postgres;

--
-- TOC entry 221 (class 1259 OID 20878)
-- Name: cashbox_employee_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW cashbox_employee_view AS
 SELECT cashbox_employee.cashbox_employee_id,
    ( SELECT subaccounts.subaccount_number
           FROM subaccounts
          WHERE (subaccounts.subaccount_id = c.subaccount_id)) AS subaccount_number,
    c.cashbox_address,
    u.user_name,
    u.user_surname,
    u.user_phone,
    ( SELECT roles.role_name
           FROM roles
          WHERE (roles.role_id = u.role_id)) AS role_name,
    cashbox_employee.cashbox_id,
    cashbox_employee.employee_id
   FROM ((cashbox_employee
     JOIN cashbox c ON ((c.cashbox_id = cashbox_employee.cashbox_id)))
     JOIN users u ON ((u.user_id = cashbox_employee.employee_id)));


ALTER TABLE cashbox_employee_view OWNER TO postgres;

--
-- TOC entry 222 (class 1259 OID 20883)
-- Name: cashbox_transaction; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE cashbox_transaction (
    cashbox_transaction_id integer NOT NULL,
    cashbox_id integer,
    cashier_id integer,
    accountant_id integer,
    owner_id integer,
    payment_id integer,
    withdrawal_id integer
);


ALTER TABLE cashbox_transaction OWNER TO postgres;

--
-- TOC entry 223 (class 1259 OID 20886)
-- Name: cashbox_transaction_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW cashbox_transaction_view AS
 SELECT cashbox_transaction.cashbox_transaction_id,
    cashbox_transaction.cashbox_id,
    cashbox_transaction.cashier_id,
    cashbox_transaction.accountant_id,
    cashbox_transaction.owner_id,
    cashbox_transaction.payment_id,
    cashbox_transaction.withdrawal_id
   FROM cashbox_transaction;


ALTER TABLE cashbox_transaction_view OWNER TO postgres;

--
-- TOC entry 224 (class 1259 OID 20890)
-- Name: cashbox_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW cashbox_view AS
 SELECT cashbox.cashbox_id,
    s.subaccount_number,
    cashbox.information,
    cashbox.cashbox_address,
    cashbox.subaccount_id
   FROM (cashbox
     JOIN subaccounts s ON ((s.subaccount_id = cashbox.subaccount_id)));


ALTER TABLE cashbox_view OWNER TO postgres;

--
-- TOC entry 225 (class 1259 OID 20894)
-- Name: chart_of_accounts; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE chart_of_accounts (
    chart_of_account_id integer NOT NULL,
    number_of_account character varying(5) NOT NULL,
    name_of_account character varying(150) NOT NULL,
    account_type_id integer
);


ALTER TABLE chart_of_accounts OWNER TO postgres;

--
-- TOC entry 226 (class 1259 OID 20897)
-- Name: chart_of_accounts_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW chart_of_accounts_view AS
 SELECT chart_of_accounts.chart_of_account_id,
    chart_of_accounts.number_of_account,
    chart_of_accounts.name_of_account,
    at.account_type_name,
    chart_of_accounts.account_type_id
   FROM (chart_of_accounts
     JOIN account_type at ON ((at.account_type_id = chart_of_accounts.account_type_id)));


ALTER TABLE chart_of_accounts_view OWNER TO postgres;

--
-- TOC entry 227 (class 1259 OID 20901)
-- Name: clients; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE clients (
    user_id integer NOT NULL,
    firm character varying(50) NOT NULL,
    firm_number character varying(10),
    location_id integer NOT NULL
);


ALTER TABLE clients OWNER TO postgres;

--
-- TOC entry 228 (class 1259 OID 20904)
-- Name: locations; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE locations (
    location_id integer NOT NULL,
    country_name character varying(30) NOT NULL,
    country_code character varying(4) NOT NULL,
    region_name character varying(30) NOT NULL,
    city_name character varying(30) NOT NULL
);


ALTER TABLE locations OWNER TO postgres;

--
-- TOC entry 229 (class 1259 OID 20907)
-- Name: clients_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW clients_view AS
 SELECT users.user_id,
    users.user_name,
    users.user_surname,
    users.user_phone,
    ( SELECT locations.country_name
           FROM locations
          WHERE (locations.location_id = clients.location_id)) AS country_name,
    ( SELECT locations.region_name
           FROM locations
          WHERE (locations.location_id = clients.location_id)) AS region_name,
    ( SELECT locations.city_name
           FROM locations
          WHERE (locations.location_id = clients.location_id)) AS city_name,
    users.user_address,
    clients.firm,
    clients.firm_number,
    ( SELECT roles.role_name
           FROM roles
          WHERE (roles.role_id = users.role_id)) AS role_name,
    users.password,
    users.user_email,
    users.activated,
    users.role_id,
    clients.location_id
   FROM (clients
     JOIN users ON ((users.user_id = clients.user_id)));


ALTER TABLE clients_view OWNER TO postgres;

--
-- TOC entry 230 (class 1259 OID 20912)
-- Name: companies; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE companies (
    company_id integer NOT NULL,
    company_name character varying(60) NOT NULL,
    company_address character varying(60) NOT NULL,
    company_phone character varying(15) NOT NULL,
    comment character varying(100)
);


ALTER TABLE companies OWNER TO postgres;

--
-- TOC entry 231 (class 1259 OID 20915)
-- Name: companies_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW companies_view AS
 SELECT companies.company_id,
    companies.company_name,
    companies.company_address,
    companies.company_phone,
    companies.comment
   FROM companies;


ALTER TABLE companies_view OWNER TO postgres;

--
-- TOC entry 232 (class 1259 OID 20919)
-- Name: company_account; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE company_account (
    company_account_id integer NOT NULL,
    company_id integer NOT NULL,
    account_id integer NOT NULL
);


ALTER TABLE company_account OWNER TO postgres;

--
-- TOC entry 233 (class 1259 OID 20922)
-- Name: company_account_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW company_account_view AS
 SELECT company_account.company_account_id,
    c.company_name,
    a.account_number,
    company_account.company_id,
    company_account.account_id
   FROM ((company_account
     JOIN companies c ON ((c.company_id = company_account.company_id)))
     JOIN accounts a ON ((a.account_id = company_account.account_id)));


ALTER TABLE company_account_view OWNER TO postgres;

--
-- TOC entry 234 (class 1259 OID 20926)
-- Name: company_employee; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE company_employee (
    company_employee_id integer NOT NULL,
    company_id integer NOT NULL,
    employee_id integer NOT NULL,
    branch_id integer
);


ALTER TABLE company_employee OWNER TO postgres;

--
-- TOC entry 235 (class 1259 OID 20929)
-- Name: company_employee_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW company_employee_view AS
 SELECT company_employee.company_employee_id,
    c.company_name,
    b.branch_name,
    e.user_name,
    e.user_surname,
    e.user_phone,
    company_employee.company_id,
    company_employee.employee_id,
    company_employee.branch_id
   FROM (((company_employee
     JOIN companies c ON ((c.company_id = company_employee.company_id)))
     JOIN users e ON ((e.user_id = company_employee.employee_id)))
     JOIN branches b ON ((b.branch_id = company_employee.branch_id)));


ALTER TABLE company_employee_view OWNER TO postgres;

--
-- TOC entry 411 (class 1259 OID 34854)
-- Name: consume_other_stocks; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE consume_other_stocks (
    consume_other_stocks_id integer NOT NULL,
    user_id integer,
    consume_other_stocks_date timestamp without time zone NOT NULL,
    execution_date timestamp(0) without time zone,
    employee_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3) NOT NULL,
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE consume_other_stocks OWNER TO postgres;

--
-- TOC entry 412 (class 1259 OID 34859)
-- Name: consume_other_stocks_list; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE consume_other_stocks_list (
    consume_other_stocks_list_id integer NOT NULL,
    consume_other_stocks_id integer NOT NULL,
    other_stocks_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE consume_other_stocks_list OWNER TO postgres;

--
-- TOC entry 237 (class 1259 OID 20937)
-- Name: measures; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE measures (
    measure_id integer NOT NULL,
    measure_name character varying(15) NOT NULL,
    measure_short_name character varying(4) NOT NULL,
    measure_unit integer
);


ALTER TABLE measures OWNER TO postgres;

--
-- TOC entry 415 (class 1259 OID 34874)
-- Name: other_stocks; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE other_stocks (
    other_stocks_id integer NOT NULL,
    company_id integer NOT NULL,
    other_stocks_name character varying(50) NOT NULL,
    volume numeric(20,5) NOT NULL,
    measure_id integer NOT NULL,
    price numeric(20,5) NOT NULL,
    currency_id integer NOT NULL,
    other_stocks_type_id integer
);


ALTER TABLE other_stocks OWNER TO postgres;

--
-- TOC entry 239 (class 1259 OID 20943)
-- Name: status; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE status (
    status_id integer NOT NULL,
    status_code character varying(4),
    status_name character varying(15),
    comment character varying(100)
);


ALTER TABLE status OWNER TO postgres;

--
-- TOC entry 3483 (class 0 OID 0)
-- Dependencies: 239
-- Name: COLUMN status.status_id; Type: COMMENT; Schema: OrmasSchema; Owner: postgres
--

COMMENT ON COLUMN status.status_id IS '
';


--
-- TOC entry 419 (class 1259 OID 34895)
-- Name: consume_other_stocks_list_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW consume_other_stocks_list_view AS
 SELECT consume_other_stocks_list.consume_other_stocks_list_id,
    consume_other_stocks_list.consume_other_stocks_id,
    p.other_stocks_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    consume_other_stocks_list.count,
    consume_other_stocks_list.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = consume_other_stocks_list.currency_id)) AS sum_currency_name,
    s.status_name,
    consume_other_stocks_list.other_stocks_id,
    consume_other_stocks_list.status_id,
    consume_other_stocks_list.currency_id
   FROM ((consume_other_stocks_list
     JOIN other_stocks p ON ((p.other_stocks_id = consume_other_stocks_list.other_stocks_id)))
     JOIN status s ON ((s.status_id = consume_other_stocks_list.status_id)));


ALTER TABLE consume_other_stocks_list_view OWNER TO postgres;

--
-- TOC entry 242 (class 1259 OID 20954)
-- Name: employees; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE employees (
    user_id integer NOT NULL,
    position_id integer NOT NULL,
    birth_date date NOT NULL,
    hire_date date NOT NULL
);


ALTER TABLE employees OWNER TO postgres;

--
-- TOC entry 243 (class 1259 OID 20957)
-- Name: positions; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE positions (
    position_id integer NOT NULL,
    position_name character varying(50) NOT NULL
);


ALTER TABLE positions OWNER TO postgres;

--
-- TOC entry 418 (class 1259 OID 34889)
-- Name: consume_other_stocks_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW consume_other_stocks_view AS
 SELECT consume_other_stocks.consume_other_stocks_id,
    to_char(consume_other_stocks.consume_other_stocks_date, 'dd.MM.yyyy hh24:mm'::text) AS consume_other_stocks_date,
    to_char(consume_other_stocks.execution_date, 'dd.MM.yyyy hh24:mm'::text) AS execution_date,
    s.status_code,
    s.status_name,
    u1.user_name AS employee_name,
    u1.user_surname AS employee_surname,
    u1.user_phone AS employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u1.user_id)))) AS employee_position_name,
    u2.user_name AS stock_employee_name,
    u2.user_surname AS stock_employee_surname,
    u2.user_phone AS stock_employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u2.user_id)))) AS stock_employee_position_name,
    consume_other_stocks.count,
    consume_other_stocks.sum,
    c.currency_short_name AS currency_name,
    consume_other_stocks.employee_id,
    consume_other_stocks.user_id,
    consume_other_stocks.status_id,
    consume_other_stocks.currency_id
   FROM ((((consume_other_stocks
     LEFT JOIN users u1 ON ((u1.user_id = consume_other_stocks.user_id)))
     LEFT JOIN users u2 ON ((u2.user_id = consume_other_stocks.employee_id)))
     LEFT JOIN status s ON ((s.status_id = consume_other_stocks.status_id)))
     LEFT JOIN currencies c ON ((c.currency_id = consume_other_stocks.currency_id)));


ALTER TABLE consume_other_stocks_view OWNER TO postgres;

--
-- TOC entry 236 (class 1259 OID 20934)
-- Name: consume_product_list; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE consume_product_list (
    consume_product_list_id integer NOT NULL,
    consume_product_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(20,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE consume_product_list OWNER TO postgres;

--
-- TOC entry 238 (class 1259 OID 20940)
-- Name: products; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE products (
    product_id integer NOT NULL,
    company_id integer NOT NULL,
    product_name character varying(50) NOT NULL,
    volume numeric(20,5) NOT NULL,
    measure_id integer NOT NULL,
    price numeric(20,5) NOT NULL,
    product_type_id integer NOT NULL,
    shelf_life integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE products OWNER TO postgres;

--
-- TOC entry 240 (class 1259 OID 20946)
-- Name: consume_product_list_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW consume_product_list_view AS
 SELECT consume_product_list.consume_product_list_id,
    consume_product_list.consume_product_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    consume_product_list.count,
    consume_product_list.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = consume_product_list.currency_id)) AS sum_currency_name,
    s.status_name,
    consume_product_list.product_id,
    consume_product_list.status_id,
    consume_product_list.currency_id
   FROM ((consume_product_list
     JOIN products p ON ((p.product_id = consume_product_list.product_id)))
     JOIN status s ON ((s.status_id = consume_product_list.status_id)));


ALTER TABLE consume_product_list_view OWNER TO postgres;

--
-- TOC entry 241 (class 1259 OID 20951)
-- Name: consume_products; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE consume_products (
    consume_product_id integer NOT NULL,
    user_id integer NOT NULL,
    consume_product_date timestamp without time zone NOT NULL,
    execution_date timestamp(0) without time zone,
    employee_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3) NOT NULL,
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE consume_products OWNER TO postgres;

--
-- TOC entry 405 (class 1259 OID 26662)
-- Name: consume_products_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW consume_products_view AS
 SELECT consume_products.consume_product_id,
    to_char(consume_products.consume_product_date, 'dd.MM.yyyy hh24:mi'::text) AS consume_product_date,
    to_char(consume_products.execution_date, 'dd.MM.yyyy hh24:mi'::text) AS execution_date,
    s.status_code,
    s.status_name,
    u1.user_name AS employee_name,
    u1.user_surname AS employee_surname,
    u1.user_phone AS employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u1.user_id)))) AS employee_position_name,
    u2.user_name AS stock_employee_name,
    u2.user_surname AS stock_employee_surname,
    u2.user_phone AS stock_employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u2.user_id)))) AS stock_employee_position_name,
    consume_products.count,
    consume_products.sum,
    c.currency_short_name AS currency_name,
    consume_products.employee_id,
    consume_products.user_id,
    consume_products.status_id,
    consume_products.currency_id
   FROM ((((consume_products
     LEFT JOIN users u1 ON ((u1.user_id = consume_products.user_id)))
     LEFT JOIN users u2 ON ((u2.user_id = consume_products.employee_id)))
     LEFT JOIN status s ON ((s.status_id = consume_products.status_id)))
     LEFT JOIN currencies c ON ((c.currency_id = consume_products.currency_id)));


ALTER TABLE consume_products_view OWNER TO postgres;

--
-- TOC entry 244 (class 1259 OID 20965)
-- Name: consume_raw_list; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE consume_raw_list (
    consume_raw_list_id integer NOT NULL,
    consume_raw_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE consume_raw_list OWNER TO postgres;

--
-- TOC entry 245 (class 1259 OID 20968)
-- Name: consume_raw_list_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW consume_raw_list_view AS
 SELECT consume_raw_list.consume_raw_list_id,
    consume_raw_list.consume_raw_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    consume_raw_list.count,
    consume_raw_list.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = consume_raw_list.currency_id)) AS sum_currency_name,
    s.status_name,
    consume_raw_list.product_id,
    consume_raw_list.status_id,
    consume_raw_list.currency_id
   FROM ((consume_raw_list
     JOIN products p ON ((p.product_id = consume_raw_list.product_id)))
     JOIN status s ON ((s.status_id = consume_raw_list.status_id)));


ALTER TABLE consume_raw_list_view OWNER TO postgres;

--
-- TOC entry 246 (class 1259 OID 20973)
-- Name: consume_raws; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE consume_raws (
    consume_raw_id integer NOT NULL,
    user_id integer NOT NULL,
    consume_raw_date timestamp without time zone NOT NULL,
    execution_date timestamp(0) without time zone,
    employee_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3) NOT NULL,
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE consume_raws OWNER TO postgres;

--
-- TOC entry 406 (class 1259 OID 26667)
-- Name: consume_raws_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW consume_raws_view AS
 SELECT consume_raws.consume_raw_id,
    to_char(consume_raws.consume_raw_date, 'dd.MM.yyyy hh24:mi'::text) AS consume_raw_date,
    to_char(consume_raws.execution_date, 'dd.MM.yyyy hh24:mi'::text) AS execution_date,
    s.status_code,
    s.status_name,
    u1.user_name AS employee_name,
    u1.user_surname AS employee_surname,
    u1.user_phone AS employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u1.user_id)))) AS employee_position_name,
    u2.user_name AS stock_employee_name,
    u2.user_surname AS stock_employee_surname,
    u2.user_phone AS stock_employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u2.user_id)))) AS stock_employee_position_name,
    consume_raws.count,
    consume_raws.sum,
    c.currency_short_name AS currency_name,
    consume_raws.employee_id,
    consume_raws.user_id,
    consume_raws.status_id,
    consume_raws.currency_id
   FROM ((((consume_raws
     LEFT JOIN users u1 ON ((u1.user_id = consume_raws.user_id)))
     LEFT JOIN users u2 ON ((u2.user_id = consume_raws.employee_id)))
     LEFT JOIN status s ON ((s.status_id = consume_raws.status_id)))
     LEFT JOIN currencies c ON ((c.currency_id = consume_raws.currency_id)));


ALTER TABLE consume_raws_view OWNER TO postgres;

--
-- TOC entry 247 (class 1259 OID 20981)
-- Name: creditors; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE creditors (
    creditor_id integer NOT NULL,
    creditor_name character varying(100),
    creditor_address character varying(100),
    crediitor_phone character varying(20),
    company_id integer,
    user_id integer
);


ALTER TABLE creditors OWNER TO postgres;

--
-- TOC entry 248 (class 1259 OID 20984)
-- Name: creditors_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW creditors_view AS
 SELECT creditors.creditor_id,
    creditors.creditor_name,
    creditors.creditor_address,
    creditors.crediitor_phone,
    creditors.company_id,
    creditors.user_id
   FROM creditors;


ALTER TABLE creditors_view OWNER TO postgres;

--
-- TOC entry 249 (class 1259 OID 20988)
-- Name: currencies_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW currencies_view AS
 SELECT currencies.currency_id,
    currencies.currency_code,
    currencies.currency_short_name,
    currencies.currency_name,
    currencies.currency_unit,
    currencies.currency_main_trade
   FROM currencies;


ALTER TABLE currencies_view OWNER TO postgres;

--
-- TOC entry 250 (class 1259 OID 20992)
-- Name: division_account; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE division_account (
    division_account_id integer NOT NULL,
    division_id integer NOT NULL,
    account_id integer NOT NULL,
    account_code character varying(30) NOT NULL
);


ALTER TABLE division_account OWNER TO postgres;

--
-- TOC entry 251 (class 1259 OID 20995)
-- Name: divisions; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE divisions (
    division_id integer NOT NULL,
    division_name character varying(100) NOT NULL,
    division_code character varying(30) NOT NULL
);


ALTER TABLE divisions OWNER TO postgres;

--
-- TOC entry 252 (class 1259 OID 20998)
-- Name: division_account_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW division_account_view AS
 SELECT division_account.division_account_id,
    d.division_name,
    a.account_number,
    ( SELECT chart_of_accounts.name_of_account
           FROM chart_of_accounts
          WHERE ((chart_of_accounts.number_of_account)::text = (a.account_number)::text)) AS account_name,
    division_account.account_code,
    division_account.division_id,
    division_account.account_id
   FROM ((division_account
     JOIN divisions d ON ((d.division_id = division_account.division_id)))
     JOIN accounts a ON ((a.account_id = division_account.account_id)));


ALTER TABLE division_account_view OWNER TO postgres;

--
-- TOC entry 253 (class 1259 OID 21003)
-- Name: division_employee; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE division_employee (
    division_employee_id integer NOT NULL,
    division_id integer NOT NULL,
    employee_id integer,
    is_contract boolean DEFAULT false NOT NULL
);


ALTER TABLE division_employee OWNER TO postgres;

--
-- TOC entry 254 (class 1259 OID 21007)
-- Name: division_employee_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW division_employee_view AS
 SELECT division_employee.division_employee_id,
    division_employee.division_id,
    division_employee.employee_id,
    division_employee.is_contract
   FROM division_employee;


ALTER TABLE division_employee_view OWNER TO postgres;

--
-- TOC entry 255 (class 1259 OID 21011)
-- Name: divisions_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW divisions_view AS
 SELECT divisions.division_id,
    divisions.division_name,
    divisions.division_code
   FROM divisions;


ALTER TABLE divisions_view OWNER TO postgres;

--
-- TOC entry 256 (class 1259 OID 21015)
-- Name: employee_product; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE employee_product (
    employee_product_id integer NOT NULL,
    employee_id integer NOT NULL,
    product_id integer NOT NULL
);


ALTER TABLE employee_product OWNER TO postgres;

--
-- TOC entry 257 (class 1259 OID 21018)
-- Name: employee_product_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW employee_product_view AS
 SELECT employee_product.employee_product_id,
    u.user_name,
    u.user_surname,
    u.user_phone,
    p.product_name,
    p.price,
    employee_product.employee_id,
    employee_product.product_id
   FROM ((employee_product
     JOIN users u ON ((u.user_id = employee_product.employee_id)))
     JOIN products p ON ((p.product_id = employee_product.product_id)));


ALTER TABLE employee_product_view OWNER TO postgres;

--
-- TOC entry 258 (class 1259 OID 21023)
-- Name: employees_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW employees_view AS
 SELECT users.user_id,
    users.user_name,
    users.user_surname,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = employees.position_id)) AS position_name,
    users.user_phone,
    users.user_address,
    to_char((employees.birth_date)::timestamp with time zone, 'dd.MM.yyyy'::text) AS birth_date,
    ( SELECT roles.role_name
           FROM roles
          WHERE (roles.role_id = users.role_id)) AS role_name,
    to_char((employees.hire_date)::timestamp with time zone, 'dd.MM.yyyy'::text) AS hire_date,
    users.password,
    users.user_email,
    users.activated,
    users.role_id,
    employees.position_id,
    de.division_employee_id,
    de.division_id,
    de.is_contract
   FROM ((employees
     JOIN users ON ((users.user_id = employees.user_id)))
     JOIN division_employee de ON ((de.employee_id = employees.user_id)));


ALTER TABLE employees_view OWNER TO postgres;

--
-- TOC entry 259 (class 1259 OID 21028)
-- Name: entries; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE entries (
    entry_id integer NOT NULL,
    entry_date timestamp without time zone NOT NULL,
    debiting_account_id integer NOT NULL,
    value numeric(20,3) NOT NULL,
    crediting_account_id integer NOT NULL,
    description character varying(200)
);


ALTER TABLE entries OWNER TO postgres;

--
-- TOC entry 260 (class 1259 OID 21031)
-- Name: entry_operation; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE entry_operation (
    entry_operation_id integer NOT NULL,
    entry_id integer NOT NULL,
    operation_id integer NOT NULL
);


ALTER TABLE entry_operation OWNER TO postgres;

--
-- TOC entry 261 (class 1259 OID 21034)
-- Name: entry_subaccount; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE entry_subaccount (
    entry_subaccount_id integer NOT NULL,
    entry_id integer NOT NULL,
    subaccount_id integer NOT NULL
);


ALTER TABLE entry_subaccount OWNER TO postgres;

--
-- TOC entry 270 (class 1259 OID 21068)
-- Name: fixed_assets; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE fixed_assets (
    fixed_assets_id integer NOT NULL,
    fixed_assets_specification_id integer NOT NULL,
    inventory_number character varying(50),
    primary_cost numeric(17,3) NOT NULL,
    stop_cost numeric(17,3),
    service_life integer,
    is_amortize boolean,
    buy_date date,
    start_of_operation_date date,
    end_of_operation_date date,
    status_id integer,
    fixed_assets_details_id integer
);


ALTER TABLE fixed_assets OWNER TO postgres;

--
-- TOC entry 273 (class 1259 OID 21079)
-- Name: fixed_assets_operations; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE fixed_assets_operations (
    fixed_assets_operation_id integer NOT NULL,
    operation_date date,
    operation_name character varying(200),
    operation_value numeric(17,3),
    increment boolean,
    decrement boolean,
    fixed_assets_id integer
);


ALTER TABLE fixed_assets_operations OWNER TO postgres;

--
-- TOC entry 3484 (class 0 OID 0)
-- Dependencies: 273
-- Name: COLUMN fixed_assets_operations.increment; Type: COMMENT; Schema: OrmasSchema; Owner: postgres
--

COMMENT ON COLUMN fixed_assets_operations.increment IS '
';


--
-- TOC entry 285 (class 1259 OID 21129)
-- Name: inventory; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE inventory (
    inventory_id integer NOT NULL,
    inventory_name character varying(200),
    inventory_cost numeric(17,3),
    department_id integer,
    location character varying(200),
    status_id integer,
    start_of_operation_date date,
    end_of_operation_date date,
    inventory_number character varying(50),
    barcode_number character varying(50),
    inventory_subaccount_id integer
);


ALTER TABLE inventory OWNER TO postgres;

--
-- TOC entry 3485 (class 0 OID 0)
-- Dependencies: 285
-- Name: COLUMN inventory.department_id; Type: COMMENT; Schema: OrmasSchema; Owner: postgres
--

COMMENT ON COLUMN inventory.department_id IS '
';


--
-- TOC entry 298 (class 1259 OID 21195)
-- Name: order_raws; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE order_raws (
    order_raw_id integer NOT NULL,
    purveyor_id integer NOT NULL,
    order_raw_date timestamp without time zone NOT NULL,
    execution_date timestamp(0) without time zone,
    employee_id integer,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3) NOT NULL,
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE order_raws OWNER TO postgres;

--
-- TOC entry 301 (class 1259 OID 21206)
-- Name: orders; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE orders (
    order_id integer NOT NULL,
    user_id integer NOT NULL,
    order_date timestamp without time zone NOT NULL,
    execution_date timestamp(0) without time zone,
    employee_id integer,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3) NOT NULL,
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE orders OWNER TO postgres;

--
-- TOC entry 305 (class 1259 OID 21221)
-- Name: payments; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE payments (
    payment_id integer NOT NULL,
    payment_date timestamp without time zone NOT NULL,
    payment_value numeric(20,3) NOT NULL,
    payment_target character varying(100),
    user_id integer,
    currency_id integer NOT NULL,
    status_id integer NOT NULL,
    account_id integer,
    subaccount_id integer,
    who character varying(100),
    cashbox_account_id integer
);


ALTER TABLE payments OWNER TO postgres;

--
-- TOC entry 309 (class 1259 OID 21236)
-- Name: payslips; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE payslips (
    payslip_id integer NOT NULL,
    payslip_date timestamp without time zone,
    payslip_value numeric(20,3) NOT NULL,
    salary_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE payslips OWNER TO postgres;

--
-- TOC entry 326 (class 1259 OID 21299)
-- Name: production_consume_raws; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE production_consume_raws (
    consume_raw_id integer NOT NULL,
    user_id integer,
    consume_raw_date timestamp without time zone NOT NULL,
    execution_date timestamp(0) without time zone,
    employee_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3) NOT NULL,
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE production_consume_raws OWNER TO postgres;

--
-- TOC entry 417 (class 1259 OID 34884)
-- Name: receipt_other_stocks; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE receipt_other_stocks (
    receipt_other_stocks_id integer NOT NULL,
    user_id integer NOT NULL,
    receipt_other_stocks_date timestamp without time zone NOT NULL,
    execution_date timestamp(0) without time zone,
    employee_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3) NOT NULL,
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE receipt_other_stocks OWNER TO postgres;

--
-- TOC entry 340 (class 1259 OID 21364)
-- Name: receipt_products; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE receipt_products (
    receipt_product_id integer NOT NULL,
    user_id integer NOT NULL,
    receipt_product_date timestamp without time zone NOT NULL,
    execution_date timestamp(0) without time zone,
    employee_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3) NOT NULL,
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE receipt_products OWNER TO postgres;

--
-- TOC entry 350 (class 1259 OID 21402)
-- Name: returns; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE returns (
    return_id integer NOT NULL,
    user_id integer,
    return_date timestamp without time zone NOT NULL,
    execution_date timestamp without time zone,
    employee_id integer,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE returns OWNER TO postgres;

--
-- TOC entry 363 (class 1259 OID 21451)
-- Name: spoilage; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE spoilage (
    spoilage_id integer NOT NULL,
    spoilage_date timestamp without time zone NOT NULL,
    employee_id integer,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3) NOT NULL,
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE spoilage OWNER TO postgres;

--
-- TOC entry 376 (class 1259 OID 21504)
-- Name: stock_transfers; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE stock_transfers (
    stock_transfer_id integer NOT NULL,
    user_id integer NOT NULL,
    stock_transfer_date timestamp without time zone NOT NULL,
    execution_date timestamp(0) without time zone,
    employee_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3) NOT NULL,
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE stock_transfers OWNER TO postgres;

--
-- TOC entry 395 (class 1259 OID 21583)
-- Name: withdrawals; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE withdrawals (
    withdrawal_id integer NOT NULL,
    withdrawal_date timestamp without time zone NOT NULL,
    withdrawal_value numeric(20,3) NOT NULL,
    user_id integer,
    subaccount_id integer,
    withdrawal_target character varying(100),
    currency_id integer,
    status_id integer,
    account_id integer,
    who character varying(100),
    cashbox_account_id integer
);


ALTER TABLE withdrawals OWNER TO postgres;

--
-- TOC entry 401 (class 1259 OID 21607)
-- Name: write_off_raws; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE write_off_raws (
    write_off_raw_id integer NOT NULL,
    user_id integer,
    write_off_raw_date timestamp without time zone NOT NULL,
    execution_date timestamp without time zone,
    employee_id integer,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE write_off_raws OWNER TO postgres;

--
-- TOC entry 403 (class 1259 OID 21615)
-- Name: write_offs; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE write_offs (
    write_off_id integer NOT NULL,
    user_id integer,
    write_off_date timestamp without time zone NOT NULL,
    execution_date timestamp without time zone,
    employee_id integer,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE write_offs OWNER TO postgres;

--
-- TOC entry 420 (class 1259 OID 34900)
-- Name: entries_all_joins_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW entries_all_joins_view AS
 SELECT entries.entry_id,
    to_char(entries.entry_date, 'dd.MM.yyyy'::text) AS entry_date,
    da.account_number AS debiting_account_number,
    entries.value,
    ca.account_number AS crediting_account_number,
    eo.operation_id,
    es.subaccount_id,
    entries.debiting_account_id,
    entries.crediting_account_id,
    entries.description,
    cp.consume_product_id,
    cr.consume_raw_id,
    fa.fixed_assets_id,
    fao.fixed_assets_operation_id,
    i.inventory_id,
    o.order_id,
    ord.order_raw_id,
    p.payment_id,
    ps.payslip_id,
    pcr.consume_raw_id AS production_consume_raw_id,
    rp.receipt_product_id,
    r.return_id,
    s.spoilage_id,
    st.stock_transfer_id,
    w.withdrawal_id,
    wo.write_off_id,
    wor.write_off_raw_id,
    pro.product_id,
    os.other_stocks_id,
    ros.receipt_other_stocks_id,
    cos.consume_other_stocks_id
   FROM (((((((((((((((((((((((((entries
     LEFT JOIN accounts da ON ((da.account_id = entries.debiting_account_id)))
     LEFT JOIN entry_operation eo ON ((eo.entry_id = entries.entry_id)))
     LEFT JOIN entry_subaccount es ON ((es.entry_id = entries.entry_id)))
     LEFT JOIN accounts ca ON ((ca.account_id = entries.crediting_account_id)))
     LEFT JOIN consume_products cp ON ((cp.consume_product_id = eo.operation_id)))
     LEFT JOIN consume_raws cr ON ((cr.consume_raw_id = eo.operation_id)))
     LEFT JOIN fixed_assets fa ON ((fa.fixed_assets_id = eo.operation_id)))
     LEFT JOIN fixed_assets_operations fao ON ((fao.fixed_assets_operation_id = eo.operation_id)))
     LEFT JOIN inventory i ON ((i.inventory_id = eo.operation_id)))
     LEFT JOIN orders o ON ((o.order_id = eo.operation_id)))
     LEFT JOIN order_raws ord ON ((ord.order_raw_id = eo.operation_id)))
     LEFT JOIN payments p ON ((p.payment_id = eo.operation_id)))
     LEFT JOIN payslips ps ON ((ps.payslip_id = eo.operation_id)))
     LEFT JOIN production_consume_raws pcr ON ((pcr.consume_raw_id = eo.operation_id)))
     LEFT JOIN receipt_products rp ON ((rp.receipt_product_id = eo.operation_id)))
     LEFT JOIN returns r ON ((r.return_id = eo.operation_id)))
     LEFT JOIN spoilage s ON ((s.spoilage_id = eo.operation_id)))
     LEFT JOIN stock_transfers st ON ((st.stock_transfer_id = eo.operation_id)))
     LEFT JOIN withdrawals w ON ((w.withdrawal_id = eo.operation_id)))
     LEFT JOIN write_offs wo ON ((wo.write_off_id = eo.operation_id)))
     LEFT JOIN write_off_raws wor ON ((wor.write_off_raw_id = eo.operation_id)))
     LEFT JOIN products pro ON ((pro.product_id = eo.operation_id)))
     LEFT JOIN other_stocks os ON ((os.other_stocks_id = eo.operation_id)))
     LEFT JOIN receipt_other_stocks ros ON ((ros.receipt_other_stocks_id = eo.operation_id)))
     LEFT JOIN consume_other_stocks cos ON ((cos.consume_other_stocks_id = eo.operation_id)))
  ORDER BY entries.entry_date;


ALTER TABLE entries_all_joins_view OWNER TO postgres;

--
-- TOC entry 262 (class 1259 OID 21037)
-- Name: entries_full_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW entries_full_view AS
 SELECT entries.entry_id,
    to_char(entries.entry_date, 'dd.MM.yyyy'::text) AS entry_date,
    da.account_number AS debiting_account_number,
    entries.value,
    ca.account_number AS crediting_account_number,
    eo.operation_id,
    es.subaccount_id,
    entries.debiting_account_id,
    entries.crediting_account_id,
    entries.description
   FROM ((((entries
     LEFT JOIN accounts da ON ((da.account_id = entries.debiting_account_id)))
     LEFT JOIN entry_operation eo ON ((eo.entry_id = entries.entry_id)))
     LEFT JOIN entry_subaccount es ON ((es.entry_id = entries.entry_id)))
     LEFT JOIN accounts ca ON ((ca.account_id = entries.crediting_account_id)))
  ORDER BY entries.entry_date;


ALTER TABLE entries_full_view OWNER TO postgres;

--
-- TOC entry 263 (class 1259 OID 21042)
-- Name: entries_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW entries_view AS
 SELECT entries.entry_id,
    to_char(entries.entry_date, 'dd.MM.yyyy'::text) AS entry_date,
    da.account_number AS debiting_account_number,
    entries.value,
    ca.account_number AS crediting_account_number,
    entries.debiting_account_id,
    entries.crediting_account_id,
    entries.description
   FROM ((entries
     JOIN accounts da ON ((da.account_id = entries.debiting_account_id)))
     JOIN accounts ca ON ((ca.account_id = entries.crediting_account_id)));


ALTER TABLE entries_view OWNER TO postgres;

--
-- TOC entry 264 (class 1259 OID 21046)
-- Name: entry_operation_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW entry_operation_view AS
 SELECT entry_operation.entry_operation_id,
    entry_operation.entry_id,
    entry_operation.operation_id
   FROM entry_operation;


ALTER TABLE entry_operation_view OWNER TO postgres;

--
-- TOC entry 265 (class 1259 OID 21050)
-- Name: entry_routing; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE entry_routing (
    entry_routing_id integer NOT NULL,
    operation_name character varying(200) NOT NULL,
    debit integer NOT NULL,
    credit integer NOT NULL
);


ALTER TABLE entry_routing OWNER TO postgres;

--
-- TOC entry 266 (class 1259 OID 21053)
-- Name: entry_routing_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW entry_routing_view AS
 SELECT entry_routing.entry_routing_id,
    entry_routing.operation_name,
    entry_routing.debit,
    entry_routing.credit
   FROM entry_routing;


ALTER TABLE entry_routing_view OWNER TO postgres;

--
-- TOC entry 267 (class 1259 OID 21057)
-- Name: entry_subaccount_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW entry_subaccount_view AS
 SELECT entry_subaccount.entry_subaccount_id,
    entry_subaccount.entry_id,
    entry_subaccount.subaccount_id
   FROM entry_subaccount;


ALTER TABLE entry_subaccount_view OWNER TO postgres;

--
-- TOC entry 268 (class 1259 OID 21061)
-- Name: financial_report; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE financial_report (
    financial_report_id integer NOT NULL,
    acc_44010 numeric(20,3),
    acc_55010 numeric(20,3),
    acc_552 numeric(20,3),
    acc_55270 numeric(20,3),
    acc_553 numeric(20,3),
    acc_55321 numeric(20,3),
    acc_44020_90 numeric(20,3),
    acc_66010_66110 numeric(20,3),
    acc_66020_66120 numeric(20,3),
    acc_66040_66140 numeric(20,3),
    acc_66050_66150 numeric(20,3),
    acc_66060_66160 numeric(20,3),
    acc_66130 numeric(20,3),
    acc_66070_66170 numeric(20,3),
    tax numeric(20,3),
    from_date date,
    till_date date
);


ALTER TABLE financial_report OWNER TO postgres;

--
-- TOC entry 269 (class 1259 OID 21064)
-- Name: financial_report_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW financial_report_view AS
 SELECT financial_report.financial_report_id,
    financial_report.acc_44010,
    financial_report.acc_55010,
    financial_report.acc_552,
    financial_report.acc_55270,
    financial_report.acc_553,
    financial_report.acc_55321,
    financial_report.acc_44020_90,
    financial_report.acc_66010_66110,
    financial_report.acc_66020_66120,
    financial_report.acc_66040_66140,
    financial_report.acc_66050_66150,
    financial_report.acc_66060_66160,
    financial_report.acc_66130,
    financial_report.acc_66070_66170,
    financial_report.tax,
    financial_report.from_date,
    financial_report.till_date
   FROM financial_report;


ALTER TABLE financial_report_view OWNER TO postgres;

--
-- TOC entry 271 (class 1259 OID 21071)
-- Name: fixed_assets_details; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE fixed_assets_details (
    fixed_assets_details_id integer NOT NULL,
    amortize_group_id integer,
    amortize_type_id integer,
    department_id integer,
    fixed_assets_location character varying(200),
    primary_cost_account_id integer,
    amortize_account_id integer,
    barcode_number character varying(50),
    amortize_value numeric(20,3)
);


ALTER TABLE fixed_assets_details OWNER TO postgres;

--
-- TOC entry 272 (class 1259 OID 21074)
-- Name: fixed_assets_details_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW fixed_assets_details_view AS
 SELECT fixed_assets_details.fixed_assets_details_id,
    ag.group_number,
    at.amortize_type_name,
    at.amortize_type_code,
    fixed_assets_details.amortize_value,
    d.division_name,
    ps.current_balance AS primary_cost_value,
    ams.current_balance AS amortize_acc_value,
    fixed_assets_details.barcode_number,
    fixed_assets_details.fixed_assets_location,
    fixed_assets_details.primary_cost_account_id,
    fixed_assets_details.amortize_account_id,
    fixed_assets_details.amortize_group_id,
    fixed_assets_details.amortize_type_id,
    fixed_assets_details.department_id
   FROM (((((fixed_assets_details
     LEFT JOIN amortize_group ag ON ((ag.amortize_group_id = fixed_assets_details.amortize_group_id)))
     LEFT JOIN amortize_type at ON ((at.amortize_type_id = fixed_assets_details.amortize_type_id)))
     LEFT JOIN divisions d ON ((d.division_id = fixed_assets_details.department_id)))
     LEFT JOIN subaccounts ps ON ((ps.subaccount_id = fixed_assets_details.primary_cost_account_id)))
     LEFT JOIN subaccounts ams ON ((ams.subaccount_id = fixed_assets_details.amortize_account_id)));


ALTER TABLE fixed_assets_details_view OWNER TO postgres;

--
-- TOC entry 274 (class 1259 OID 21082)
-- Name: fixed_assets_operations_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW fixed_assets_operations_view AS
 SELECT fixed_assets_operations.fixed_assets_operation_id,
    to_char((fixed_assets_operations.operation_date)::timestamp with time zone, 'dd.MM.yyyy'::text) AS operation_date,
    fixed_assets_operations.operation_name,
    fixed_assets_operations.operation_value,
    fixed_assets_operations.increment,
    fixed_assets_operations.decrement,
    fixed_assets_operations.fixed_assets_id
   FROM fixed_assets_operations;


ALTER TABLE fixed_assets_operations_view OWNER TO postgres;

--
-- TOC entry 275 (class 1259 OID 21086)
-- Name: fixed_assets_specification; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE fixed_assets_specification (
    fixed_assets_specification_id integer NOT NULL,
    fixed_assets_name character varying(200),
    factory_number character varying(30),
    developer character varying(100),
    document character varying(200),
    object_characters character varying(400),
    condition character varying(100),
    date_of_construction date
);


ALTER TABLE fixed_assets_specification OWNER TO postgres;

--
-- TOC entry 276 (class 1259 OID 21092)
-- Name: fixed_assets_specification_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW fixed_assets_specification_view AS
 SELECT fixed_assets_specification.fixed_assets_specification_id,
    fixed_assets_specification.fixed_assets_name,
    fixed_assets_specification.factory_number,
    fixed_assets_specification.developer,
    fixed_assets_specification.document,
    fixed_assets_specification.object_characters,
    fixed_assets_specification.condition,
    to_char((fixed_assets_specification.date_of_construction)::timestamp with time zone, 'dd.MM.yyyy'::text) AS date_of_construction
   FROM fixed_assets_specification;


ALTER TABLE fixed_assets_specification_view OWNER TO postgres;

--
-- TOC entry 277 (class 1259 OID 21096)
-- Name: posting_fixed_assets; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE posting_fixed_assets (
    posting_fixed_assets_id integer NOT NULL,
    user_id integer,
    subaccount_id integer,
    account_id integer,
    fixed_assets_id integer,
    inventory_id integer
);


ALTER TABLE posting_fixed_assets OWNER TO postgres;

--
-- TOC entry 278 (class 1259 OID 21099)
-- Name: fixed_assets_union_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW fixed_assets_union_view AS
 SELECT fixed_assets.fixed_assets_id,
    fas.fixed_assets_name,
    ( SELECT divisions.division_name
           FROM divisions
          WHERE (divisions.division_id = fad.department_id)) AS division_name,
    fixed_assets.primary_cost,
    fixed_assets.stop_cost,
    ( SELECT subaccounts.current_balance
           FROM subaccounts
          WHERE (subaccounts.subaccount_id = fad.amortize_account_id)) AS amortize_sum,
    fixed_assets.inventory_number,
    fad.amortize_value,
    fixed_assets.service_life,
    fixed_assets.is_amortize,
    s.status_name,
    to_char((fixed_assets.buy_date)::timestamp with time zone, 'dd.MM.yyyy'::text) AS buy_date,
    to_char((fixed_assets.start_of_operation_date)::timestamp with time zone, 'dd.MM.yyyy'::text) AS start_of_operation_date,
    to_char((fixed_assets.end_of_operation_date)::timestamp with time zone, 'dd.MM.yyyy'::text) AS end_of_operation_date,
    fad.fixed_assets_location,
    fad.barcode_number,
    fas.factory_number,
    fas.developer,
    fas.document,
    fas.object_characters,
    fas.condition,
    to_char((fas.date_of_construction)::timestamp with time zone, 'dd.MM.yyyy'::text) AS date_of_construction,
    fas.fixed_assets_specification_id,
    fixed_assets.status_id,
    fad.fixed_assets_details_id,
    fad.amortize_group_id,
    fad.amortize_type_id,
    fad.department_id,
    fad.primary_cost_account_id,
    fad.amortize_account_id,
    pfa.posting_fixed_assets_id,
    pfa.user_id,
    pfa.subaccount_id,
    pfa.account_id
   FROM ((((fixed_assets
     LEFT JOIN fixed_assets_specification fas ON ((fas.fixed_assets_specification_id = fixed_assets.fixed_assets_specification_id)))
     LEFT JOIN fixed_assets_details fad ON ((fad.fixed_assets_details_id = fixed_assets.fixed_assets_details_id)))
     LEFT JOIN posting_fixed_assets pfa ON ((pfa.fixed_assets_id = fixed_assets.fixed_assets_id)))
     LEFT JOIN status s ON ((s.status_id = fixed_assets.status_id)));


ALTER TABLE fixed_assets_union_view OWNER TO postgres;

--
-- TOC entry 279 (class 1259 OID 21104)
-- Name: fixed_assets_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW fixed_assets_view AS
 SELECT fixed_assets.fixed_assets_id,
    fs.fixed_assets_name,
    fixed_assets.inventory_number,
    fixed_assets.primary_cost,
    fixed_assets.stop_cost,
    ( SELECT subaccounts.current_balance
           FROM subaccounts
          WHERE (subaccounts.subaccount_id = fd.primary_cost_account_id)) AS primary_cost_value,
    ( SELECT subaccounts.current_balance
           FROM subaccounts
          WHERE (subaccounts.subaccount_id = fd.amortize_account_id)) AS amortize_value,
    ( SELECT divisions.division_name
           FROM divisions
          WHERE (divisions.division_id = fd.department_id)) AS division_name,
    s.status_name,
    fixed_assets.service_life,
    fixed_assets.is_amortize,
    to_char((fixed_assets.buy_date)::timestamp with time zone, 'dd.MM.yyyy'::text) AS buy_date,
    to_char((fixed_assets.start_of_operation_date)::timestamp with time zone, 'dd.MM.yyyy'::text) AS start_of_operation_date,
    to_char((fixed_assets.end_of_operation_date)::timestamp with time zone, 'dd.MM.yyyy'::text) AS end_of_operation_date,
    fixed_assets.fixed_assets_specification_id,
    fixed_assets.status_id,
    fixed_assets.fixed_assets_details_id
   FROM (((fixed_assets
     LEFT JOIN fixed_assets_specification fs ON ((fs.fixed_assets_specification_id = fixed_assets.fixed_assets_specification_id)))
     LEFT JOIN fixed_assets_details fd ON ((fd.fixed_assets_details_id = fixed_assets.fixed_assets_details_id)))
     LEFT JOIN status s ON ((s.status_id = fixed_assets.status_id)));


ALTER TABLE fixed_assets_view OWNER TO postgres;

--
-- TOC entry 280 (class 1259 OID 21109)
-- Name: id_seq; Type: SEQUENCE; Schema: OrmasSchema; Owner: postgres
--

CREATE SEQUENCE id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    MAXVALUE 9999999999
    CACHE 1;


ALTER TABLE id_seq OWNER TO postgres;

--
-- TOC entry 281 (class 1259 OID 21111)
-- Name: inv_seq; Type: SEQUENCE; Schema: OrmasSchema; Owner: postgres
--

CREATE SEQUENCE inv_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    MAXVALUE 999999999
    CACHE 1;


ALTER TABLE inv_seq OWNER TO postgres;

--
-- TOC entry 282 (class 1259 OID 21113)
-- Name: inventorization_list; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE inventorization_list (
    inventorization_list_id integer NOT NULL,
    inventorization_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE inventorization_list OWNER TO postgres;

--
-- TOC entry 283 (class 1259 OID 21116)
-- Name: inventorization_list_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW inventorization_list_view AS
 SELECT inventorization_list.inventorization_list_id,
    inventorization_list.inventorization_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    inventorization_list.count,
    inventorization_list.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = inventorization_list.currency_id)) AS sum_currency_name,
    s.status_name,
    inventorization_list.product_id,
    inventorization_list.status_id,
    inventorization_list.currency_id
   FROM ((inventorization_list
     JOIN products p ON ((p.product_id = inventorization_list.product_id)))
     JOIN status s ON ((s.status_id = inventorization_list.status_id)));


ALTER TABLE inventorization_list_view OWNER TO postgres;

--
-- TOC entry 284 (class 1259 OID 21121)
-- Name: inventorizations; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE inventorizations (
    inventorization_id integer NOT NULL,
    user_id integer NOT NULL,
    inventorization_date timestamp without time zone NOT NULL,
    execution_date timestamp(0) without time zone,
    employee_id integer,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3) NOT NULL,
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE inventorizations OWNER TO postgres;

--
-- TOC entry 407 (class 1259 OID 26672)
-- Name: inventorizations_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW inventorizations_view AS
 SELECT inventorizations.inventorization_id,
    to_char(inventorizations.inventorization_date, 'dd.MM.yyyy hh24:mi'::text) AS inventorization_date,
    to_char(inventorizations.execution_date, 'dd.MM.yyyy hh24:mi'::text) AS execution_date,
    s.status_code,
    s.status_name,
    u1.user_name AS employee_name,
    u1.user_surname AS employee_surname,
    u1.user_phone AS employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u1.user_id)))) AS employee_position_name,
    u2.user_name AS stock_employee_name,
    u2.user_surname AS stock_employee_surname,
    u2.user_phone AS stock_employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u2.user_id)))) AS stock_employee_position_name,
    inventorizations.count,
    inventorizations.sum,
    c.currency_short_name AS currency_name,
    inventorizations.employee_id,
    inventorizations.user_id,
    inventorizations.status_id,
    inventorizations.currency_id
   FROM ((((inventorizations
     LEFT JOIN users u1 ON ((u1.user_id = inventorizations.user_id)))
     LEFT JOIN users u2 ON ((u2.user_id = inventorizations.employee_id)))
     LEFT JOIN status s ON ((s.status_id = inventorizations.status_id)))
     LEFT JOIN currencies c ON ((c.currency_id = inventorizations.currency_id)));


ALTER TABLE inventorizations_view OWNER TO postgres;

--
-- TOC entry 286 (class 1259 OID 21135)
-- Name: inventory_history; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE inventory_history (
    inventory_history_id integer NOT NULL,
    inventory_id integer,
    comment character varying(300),
    change_date date
);


ALTER TABLE inventory_history OWNER TO postgres;

--
-- TOC entry 426 (class 1259 OID 34935)
-- Name: inventory_history_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW inventory_history_view AS
 SELECT inventory_history.inventory_history_id,
    inventory_history.inventory_id,
    inventory_history.comment,
    to_char((inventory_history.change_date)::timestamp with time zone, 'dd.MM.yyyy'::text) AS change_date
   FROM inventory_history;


ALTER TABLE inventory_history_view OWNER TO postgres;

--
-- TOC entry 421 (class 1259 OID 34905)
-- Name: inventory_union_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW inventory_union_view AS
 SELECT inventory.inventory_id,
    inventory.inventory_name,
    inventory.inventory_cost,
    inventory.inventory_number,
    inventory.barcode_number,
    divisions.division_name,
    s.status_name,
    inventory.location,
    inventory.start_of_operation_date,
    inventory.end_of_operation_date,
    inventory.status_id,
    inventory.department_id,
    inventory.inventory_subaccount_id,
    pfa.posting_fixed_assets_id,
    pfa.user_id,
    pfa.subaccount_id,
    pfa.account_id
   FROM ((((inventory
     LEFT JOIN status s ON ((s.status_id = inventory.status_id)))
     LEFT JOIN divisions ON ((divisions.division_id = inventory.department_id)))
     LEFT JOIN posting_fixed_assets pfa ON ((pfa.inventory_id = inventory.inventory_id)))
     LEFT JOIN subaccounts ON ((subaccounts.subaccount_id = inventory.inventory_subaccount_id)));


ALTER TABLE inventory_union_view OWNER TO postgres;

--
-- TOC entry 427 (class 1259 OID 34939)
-- Name: inventory_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW inventory_view AS
 SELECT inventory.inventory_id,
    inventory.inventory_name,
    inventory.inventory_cost,
    inventory.inventory_number,
    inventory.barcode_number,
    divisions.division_name,
    s.status_name,
    inventory.location,
    inventory.start_of_operation_date,
    inventory.end_of_operation_date,
    inventory.status_id,
    inventory.department_id,
    inventory.inventory_subaccount_id
   FROM (((inventory
     LEFT JOIN status s ON ((s.status_id = inventory.status_id)))
     LEFT JOIN divisions ON ((divisions.division_id = inventory.department_id)))
     LEFT JOIN subaccounts ON ((subaccounts.subaccount_id = inventory.inventory_subaccount_id)));


ALTER TABLE inventory_view OWNER TO postgres;

--
-- TOC entry 287 (class 1259 OID 21147)
-- Name: jobprice; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE jobprice (
    jobprice_id integer NOT NULL,
    product_id integer NOT NULL,
    value numeric(20,3) NOT NULL,
    currency_id integer NOT NULL,
    volume numeric(20,3) NOT NULL,
    measure_id integer NOT NULL,
    position_id integer NOT NULL
);


ALTER TABLE jobprice OWNER TO postgres;

--
-- TOC entry 288 (class 1259 OID 21150)
-- Name: jobprice_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW jobprice_view AS
 SELECT jobprice.jobprice_id,
    p.product_name,
    jobprice.value,
    c.currency_short_name AS currency_name,
    jobprice.volume,
    m.measure_name,
    pos.position_name,
    jobprice.product_id,
    jobprice.currency_id,
    jobprice.measure_id,
    jobprice.position_id
   FROM ((((jobprice
     JOIN products p ON ((p.product_id = jobprice.product_id)))
     JOIN currencies c ON ((c.currency_id = jobprice.currency_id)))
     JOIN measures m ON ((m.measure_id = jobprice.measure_id)))
     JOIN positions pos ON ((pos.position_id = jobprice.position_id)));


ALTER TABLE jobprice_view OWNER TO postgres;

--
-- TOC entry 289 (class 1259 OID 21155)
-- Name: jobsheet; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE jobsheet (
    jobsheet_id integer NOT NULL,
    jobsheet_date date NOT NULL,
    count numeric(20,3) NOT NULL,
    product_id integer NOT NULL,
    employee_id integer NOT NULL
);


ALTER TABLE jobsheet OWNER TO postgres;

--
-- TOC entry 290 (class 1259 OID 21158)
-- Name: jobsheet_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW jobsheet_view AS
 SELECT jobsheet.jobsheet_id,
    to_char((jobsheet.jobsheet_date)::timestamp with time zone, 'dd.MM.yyyy'::text) AS jobsheet_date,
    e.user_name,
    e.user_surname,
    e.user_phone,
    p.product_name,
    jobsheet.count,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    jobsheet.product_id,
    jobsheet.employee_id
   FROM ((jobsheet
     JOIN products p ON ((p.product_id = jobsheet.product_id)))
     JOIN users e ON ((e.user_id = jobsheet.employee_id)));


ALTER TABLE jobsheet_view OWNER TO postgres;

--
-- TOC entry 291 (class 1259 OID 21163)
-- Name: locations_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW locations_view AS
 SELECT locations.location_id,
    locations.country_name,
    locations.country_code,
    locations.region_name,
    locations.city_name
   FROM locations;


ALTER TABLE locations_view OWNER TO postgres;

--
-- TOC entry 413 (class 1259 OID 34864)
-- Name: low_value_stock; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE low_value_stock (
    low_value_stock_id integer NOT NULL,
    other_stocks_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL,
    warehouse_id integer
);


ALTER TABLE low_value_stock OWNER TO postgres;

--
-- TOC entry 414 (class 1259 OID 34869)
-- Name: low_value_stock_history; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE low_value_stock_history (
    low_value_stock_id integer NOT NULL,
    other_stocks_id integer,
    count numeric(15,5),
    sum numeric(20,3),
    status_id integer,
    currency_id integer,
    warehouse_id integer,
    history_date timestamp without time zone
);


ALTER TABLE low_value_stock_history OWNER TO postgres;

--
-- TOC entry 334 (class 1259 OID 21334)
-- Name: warehouse; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE warehouse (
    warehouse_id integer NOT NULL,
    warehouse_name character varying(60) NOT NULL,
    warehouse_address character varying(60) NOT NULL,
    warehouse_phone character varying(15),
    warehouse_type_id integer NOT NULL,
    subaccount_id integer NOT NULL
);


ALTER TABLE warehouse OWNER TO postgres;

--
-- TOC entry 422 (class 1259 OID 34910)
-- Name: low_value_stock_history_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW low_value_stock_history_view AS
 SELECT low_value_stock_history.low_value_stock_id,
    p.other_stocks_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    low_value_stock_history.count,
    low_value_stock_history.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = low_value_stock_history.currency_id)) AS sum_currency_name,
    w.warehouse_name,
    ( SELECT subaccounts.subaccount_number
           FROM subaccounts
          WHERE (subaccounts.subaccount_id = w.subaccount_id)) AS subaccount_number,
    s.status_name,
    low_value_stock_history.other_stocks_id,
    low_value_stock_history.status_id,
    low_value_stock_history.currency_id,
    low_value_stock_history.warehouse_id,
    low_value_stock_history.history_date
   FROM (((low_value_stock_history
     LEFT JOIN other_stocks p ON ((p.other_stocks_id = low_value_stock_history.other_stocks_id)))
     LEFT JOIN status s ON ((s.status_id = low_value_stock_history.status_id)))
     LEFT JOIN warehouse w ON ((w.warehouse_id = low_value_stock_history.warehouse_id)));


ALTER TABLE low_value_stock_history_view OWNER TO postgres;

--
-- TOC entry 423 (class 1259 OID 34915)
-- Name: low_value_stock_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW low_value_stock_view AS
 SELECT low_value_stock.low_value_stock_id,
    p.other_stocks_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    low_value_stock.count,
    low_value_stock.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = low_value_stock.currency_id)) AS sum_currency_name,
    w.warehouse_name,
    ( SELECT subaccounts.subaccount_number
           FROM subaccounts
          WHERE (subaccounts.subaccount_id = w.subaccount_id)) AS subaccount_number,
    s.status_name,
    low_value_stock.other_stocks_id,
    low_value_stock.status_id,
    low_value_stock.currency_id,
    low_value_stock.warehouse_id
   FROM (((low_value_stock
     JOIN other_stocks p ON ((p.other_stocks_id = low_value_stock.other_stocks_id)))
     JOIN status s ON ((s.status_id = low_value_stock.status_id)))
     JOIN warehouse w ON ((w.warehouse_id = low_value_stock.warehouse_id)))
  ORDER BY p.other_stocks_name;


ALTER TABLE low_value_stock_view OWNER TO postgres;

--
-- TOC entry 292 (class 1259 OID 21167)
-- Name: measures_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW measures_view AS
 SELECT measures.measure_id,
    measures.measure_name,
    measures.measure_short_name,
    measures.measure_unit
   FROM measures;


ALTER TABLE measures_view OWNER TO postgres;

--
-- TOC entry 293 (class 1259 OID 21171)
-- Name: net_cost; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE net_cost (
    net_cost_id integer NOT NULL,
    net_cost_date timestamp without time zone NOT NULL,
    net_cost_value numeric(20,3) NOT NULL,
    currency_id integer NOT NULL,
    product_id integer NOT NULL,
    is_outdated boolean
);


ALTER TABLE net_cost OWNER TO postgres;

--
-- TOC entry 408 (class 1259 OID 26681)
-- Name: net_cost_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW net_cost_view AS
 SELECT net_cost.net_cost_id,
    to_char(net_cost.net_cost_date, 'dd.MM.yyyy hh24:mi'::text) AS net_cost_date,
    p.product_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    net_cost.net_cost_value,
    c.currency_short_name AS currency_name,
    net_cost.currency_id,
    net_cost.product_id,
    net_cost.is_outdated
   FROM ((net_cost
     JOIN products p ON ((p.product_id = net_cost.product_id)))
     JOIN currencies c ON ((c.currency_id = net_cost.currency_id)));


ALTER TABLE net_cost_view OWNER TO postgres;

--
-- TOC entry 294 (class 1259 OID 21179)
-- Name: order_list; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE order_list (
    order_list_id integer NOT NULL,
    order_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE order_list OWNER TO postgres;

--
-- TOC entry 295 (class 1259 OID 21182)
-- Name: order_list_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW order_list_view AS
 SELECT order_list.order_list_id,
    order_list.order_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    order_list.count,
    order_list.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = order_list.currency_id)) AS sum_currency_name,
    s.status_name,
    order_list.product_id,
    order_list.status_id,
    order_list.currency_id
   FROM ((order_list
     JOIN products p ON ((p.product_id = order_list.product_id)))
     JOIN status s ON ((s.status_id = order_list.status_id)));


ALTER TABLE order_list_view OWNER TO postgres;

--
-- TOC entry 296 (class 1259 OID 21187)
-- Name: order_raw_list; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE order_raw_list (
    order_raw_list_id integer NOT NULL,
    order_raw_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE order_raw_list OWNER TO postgres;

--
-- TOC entry 297 (class 1259 OID 21190)
-- Name: order_raw_list_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW order_raw_list_view AS
 SELECT order_raw_list.order_raw_list_id,
    order_raw_list.order_raw_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    order_raw_list.count,
    order_raw_list.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = order_raw_list.currency_id)) AS sum_currency_name,
    s.status_name,
    order_raw_list.product_id,
    order_raw_list.status_id,
    order_raw_list.currency_id
   FROM ((order_raw_list
     JOIN products p ON ((p.product_id = order_raw_list.product_id)))
     JOIN status s ON ((s.status_id = order_raw_list.status_id)));


ALTER TABLE order_raw_list_view OWNER TO postgres;

--
-- TOC entry 299 (class 1259 OID 21198)
-- Name: purveyors; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE purveyors (
    user_id integer NOT NULL,
    company_name character varying(100) NOT NULL,
    location_id integer NOT NULL
);


ALTER TABLE purveyors OWNER TO postgres;

--
-- TOC entry 300 (class 1259 OID 21201)
-- Name: order_raws_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW order_raws_view AS
 SELECT order_raws.order_raw_id,
    to_char(order_raws.order_raw_date, 'dd.MM.yyyy hh24:mi'::text) AS order_raw_date,
    to_char(order_raws.execution_date, 'dd.MM.yyyy hh24:mi'::text) AS execution_date,
    s.status_code,
    s.status_name,
    u1.user_name AS purveyor_name,
    u1.user_surname AS purveyor_surname,
    u1.user_phone AS purveyor_phone,
    ( SELECT purveyors.company_name
           FROM purveyors
          WHERE (purveyors.user_id = u1.user_id)) AS purveyor_company_name,
    u2.user_name AS employee_name,
    u2.user_surname AS employee_surname,
    u2.user_phone AS employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u2.user_id)))) AS employee_position_name,
    order_raws.count,
    order_raws.sum,
    c.currency_short_name AS currency_name,
    order_raws.employee_id,
    order_raws.purveyor_id,
    order_raws.status_id,
    order_raws.currency_id
   FROM ((((order_raws
     LEFT JOIN users u1 ON ((u1.user_id = order_raws.purveyor_id)))
     LEFT JOIN users u2 ON ((u2.user_id = order_raws.employee_id)))
     LEFT JOIN status s ON ((s.status_id = order_raws.status_id)))
     LEFT JOIN currencies c ON ((c.currency_id = order_raws.currency_id)));


ALTER TABLE order_raws_view OWNER TO postgres;

--
-- TOC entry 302 (class 1259 OID 21209)
-- Name: orders_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW orders_view AS
 SELECT orders.order_id,
    to_char(orders.order_date, 'dd.MM.yyyy hh24:mi'::text) AS order_date,
    to_char(orders.execution_date, 'dd.MM.yyyy hh24:mi'::text) AS execution_date,
    s.status_code,
    s.status_name,
    u1.user_name AS client_name,
    u1.user_surname AS client_surname,
    u1.user_phone AS client_phone,
    u1.user_address AS clinet_address,
    ( SELECT clients.firm
           FROM clients
          WHERE (clients.user_id = u1.user_id)) AS client_firm,
    u2.user_name AS employee_name,
    u2.user_surname AS employee_surname,
    u2.user_phone AS employee_phone,
    orders.count,
    orders.sum,
    c.currency_short_name AS currency_name,
    orders.employee_id,
    orders.user_id,
    orders.status_id,
    orders.currency_id
   FROM ((((orders
     LEFT JOIN users u1 ON ((u1.user_id = orders.user_id)))
     LEFT JOIN users u2 ON ((u2.user_id = orders.employee_id)))
     LEFT JOIN status s ON ((s.status_id = orders.status_id)))
     LEFT JOIN currencies c ON ((c.currency_id = orders.currency_id)));


ALTER TABLE orders_view OWNER TO postgres;

--
-- TOC entry 431 (class 1259 OID 52488)
-- Name: other_stocks_type; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE other_stocks_type (
    other_stocks_type_id integer NOT NULL,
    other_stocks_type_name character varying(50) NOT NULL,
    other_stocks_type_short_name character varying(10) NOT NULL,
    other_stocks_type_code character varying(15)
);


ALTER TABLE other_stocks_type OWNER TO postgres;

--
-- TOC entry 432 (class 1259 OID 52493)
-- Name: other_stocks_type_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW other_stocks_type_view AS
 SELECT other_stocks_type.other_stocks_type_id,
    other_stocks_type.other_stocks_type_name,
    other_stocks_type.other_stocks_type_short_name,
    other_stocks_type.other_stocks_type_code
   FROM other_stocks_type;


ALTER TABLE other_stocks_type_view OWNER TO postgres;

--
-- TOC entry 433 (class 1259 OID 52497)
-- Name: other_stocks_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW other_stocks_view AS
 SELECT other_stocks.other_stocks_id,
    other_stocks.other_stocks_name,
    other_stocks.price,
    cur.currency_short_name AS currency,
    other_stocks.volume,
    m.measure_short_name AS measure_name,
    c.company_name,
    oths.other_stocks_type_name,
    other_stocks.company_id,
    other_stocks.measure_id,
    other_stocks.currency_id,
    other_stocks.other_stocks_type_id
   FROM ((((other_stocks
     JOIN companies c ON ((c.company_id = other_stocks.company_id)))
     JOIN measures m ON ((m.measure_id = other_stocks.measure_id)))
     JOIN currencies cur ON ((cur.currency_id = other_stocks.currency_id)))
     JOIN other_stocks_type oths ON ((oths.other_stocks_type_id = other_stocks.other_stocks_type_id)))
  ORDER BY other_stocks.other_stocks_name;


ALTER TABLE other_stocks_view OWNER TO postgres;

--
-- TOC entry 303 (class 1259 OID 21214)
-- Name: payment_employee; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE payment_employee (
    payment_employee_id integer NOT NULL,
    payment_id integer NOT NULL,
    employee_id integer NOT NULL
);


ALTER TABLE payment_employee OWNER TO postgres;

--
-- TOC entry 304 (class 1259 OID 21217)
-- Name: payment_employee_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW payment_employee_view AS
 SELECT payment_employee.payment_employee_id,
    payment_employee.payment_id,
    payment_employee.employee_id
   FROM payment_employee;


ALTER TABLE payment_employee_view OWNER TO postgres;

--
-- TOC entry 306 (class 1259 OID 21224)
-- Name: payments_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW payments_view AS
 SELECT payments.payment_id,
    to_char(payments.payment_date, 'dd.MM.yyyy hh24:mi'::text) AS payment_date,
    u.user_name,
    u.user_surname,
    u.user_phone,
    payments.payment_value,
    c.currency_short_name AS currency_name,
    payments.payment_target,
    a.account_number,
    sa.subaccount_number,
    payments.who,
    s.status_name,
    payments.user_id,
    payments.currency_id,
    payments.status_id,
    payments.account_id,
    payments.subaccount_id,
    payments.cashbox_account_id
   FROM (((((payments
     LEFT JOIN currencies c ON ((c.currency_id = payments.currency_id)))
     LEFT JOIN status s ON ((s.status_id = payments.status_id)))
     LEFT JOIN accounts a ON ((a.account_id = payments.account_id)))
     LEFT JOIN subaccounts sa ON ((sa.subaccount_id = payments.subaccount_id)))
     LEFT JOIN users u ON ((u.user_id = payments.user_id)));


ALTER TABLE payments_view OWNER TO postgres;

--
-- TOC entry 307 (class 1259 OID 21229)
-- Name: payslip_order; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE payslip_order (
    payslip_order_id integer NOT NULL,
    payslip_id integer NOT NULL,
    order_id integer
);


ALTER TABLE payslip_order OWNER TO postgres;

--
-- TOC entry 308 (class 1259 OID 21232)
-- Name: payslip_order_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW payslip_order_view AS
 SELECT payslip_order.payslip_order_id,
    payslip_order.payslip_id,
    payslip_order.order_id
   FROM payslip_order;


ALTER TABLE payslip_order_view OWNER TO postgres;

--
-- TOC entry 310 (class 1259 OID 21239)
-- Name: payslips_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW payslips_view AS
 SELECT payslips.payslip_id,
    to_char(payslips.payslip_date, 'dd.MM.yyyy hh24:mi'::text) AS payslip_date,
    payslips.payslip_value,
    c.currency_short_name AS currency_name,
    payslips.salary_id,
    payslips.currency_id
   FROM (payslips
     JOIN currencies c ON ((c.currency_id = payslips.currency_id)));


ALTER TABLE payslips_view OWNER TO postgres;

--
-- TOC entry 311 (class 1259 OID 21243)
-- Name: percent_rate; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE percent_rate (
    percent_rate_id integer NOT NULL,
    value numeric(20,3),
    condition character varying(100),
    position_id integer NOT NULL
);


ALTER TABLE percent_rate OWNER TO postgres;

--
-- TOC entry 312 (class 1259 OID 21246)
-- Name: percent_rate_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW percent_rate_view AS
 SELECT percent_rate.percent_rate_id,
    percent_rate.value,
    percent_rate.condition,
    percent_rate.position_id
   FROM (percent_rate
     JOIN positions p ON ((p.position_id = percent_rate.position_id)));


ALTER TABLE percent_rate_view OWNER TO postgres;

--
-- TOC entry 313 (class 1259 OID 21250)
-- Name: photos; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE photos (
    photo_id integer NOT NULL,
    user_id integer,
    product_id integer,
    photo_source character varying(100)
);


ALTER TABLE photos OWNER TO postgres;

--
-- TOC entry 314 (class 1259 OID 21253)
-- Name: photos_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW photos_view AS
 SELECT photos.photo_id,
    photos.user_id,
    photos.product_id,
    photos.photo_source
   FROM photos;


ALTER TABLE photos_view OWNER TO postgres;

--
-- TOC entry 315 (class 1259 OID 21257)
-- Name: positions_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW positions_view AS
 SELECT positions.position_id,
    positions.position_name
   FROM positions;


ALTER TABLE positions_view OWNER TO postgres;

--
-- TOC entry 316 (class 1259 OID 21261)
-- Name: postging_fixed_assets_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW postging_fixed_assets_view AS
 SELECT posting_fixed_assets.posting_fixed_assets_id,
    users.user_surname,
    ( SELECT coa.name_of_account
           FROM chart_of_accounts coa
          WHERE ((coa.number_of_account)::text = (accounts.account_number)::text)) AS account_name,
    posting_fixed_assets.user_id,
    posting_fixed_assets.subaccount_id,
    posting_fixed_assets.account_id,
    posting_fixed_assets.fixed_assets_id,
    posting_fixed_assets.inventory_id
   FROM ((posting_fixed_assets
     LEFT JOIN users ON ((users.user_id = posting_fixed_assets.user_id)))
     LEFT JOIN accounts ON ((accounts.account_id = posting_fixed_assets.account_id)));


ALTER TABLE postging_fixed_assets_view OWNER TO postgres;

--
-- TOC entry 317 (class 1259 OID 21266)
-- Name: prices; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE prices (
    price_id integer NOT NULL,
    price_date timestamp without time zone NOT NULL,
    price_value numeric(20,5) NOT NULL,
    currency_id integer NOT NULL,
    product_id integer NOT NULL,
    is_outdated boolean
);


ALTER TABLE prices OWNER TO postgres;

--
-- TOC entry 318 (class 1259 OID 21269)
-- Name: prices_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW prices_view AS
 SELECT prices.price_id,
    to_char(prices.price_date, 'dd.MM.yyyy hh24:mi'::text) AS price_date,
    p.product_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    prices.price_value,
    c.currency_short_name AS currency_name,
    prices.currency_id,
    prices.product_id,
    prices.is_outdated
   FROM ((prices
     JOIN products p ON ((p.product_id = prices.product_id)))
     JOIN currencies c ON ((c.currency_id = prices.currency_id)));


ALTER TABLE prices_view OWNER TO postgres;

--
-- TOC entry 319 (class 1259 OID 21274)
-- Name: product_branch; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE product_branch (
    product_branch_id integer NOT NULL,
    product_id integer NOT NULL,
    branch_id integer NOT NULL
);


ALTER TABLE product_branch OWNER TO postgres;

--
-- TOC entry 320 (class 1259 OID 21277)
-- Name: product_branch_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW product_branch_view AS
 SELECT product_branch.product_branch_id,
    b.branch_name,
    b.branch_address,
    p.product_name,
    p.price,
    product_branch.product_id,
    product_branch.branch_id
   FROM ((product_branch
     JOIN products p ON ((p.product_id = product_branch.product_id)))
     JOIN branches b ON ((b.branch_id = product_branch.branch_id)));


ALTER TABLE product_branch_view OWNER TO postgres;

--
-- TOC entry 321 (class 1259 OID 21281)
-- Name: product_type; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE product_type (
    product_type_id integer NOT NULL,
    product_type_name character varying(50) NOT NULL,
    product_type_short_name character varying(10) NOT NULL,
    product_type_code character varying(15)
);


ALTER TABLE product_type OWNER TO postgres;

--
-- TOC entry 322 (class 1259 OID 21284)
-- Name: product_types_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW product_types_view AS
 SELECT product_type.product_type_id,
    product_type.product_type_name,
    product_type.product_type_short_name,
    product_type.product_type_code
   FROM product_type;


ALTER TABLE product_types_view OWNER TO postgres;

--
-- TOC entry 323 (class 1259 OID 21288)
-- Name: production; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE production (
    production_id integer NOT NULL,
    production_date date NOT NULL,
    expiry_date date,
    session_start time without time zone NOT NULL,
    session_end time without time zone
);


ALTER TABLE production OWNER TO postgres;

--
-- TOC entry 324 (class 1259 OID 21291)
-- Name: production_consume_raw_list; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE production_consume_raw_list (
    consume_raw_list_id integer NOT NULL,
    consume_raw_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE production_consume_raw_list OWNER TO postgres;

--
-- TOC entry 325 (class 1259 OID 21294)
-- Name: production_consume_raw_list_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW production_consume_raw_list_view AS
 SELECT production_consume_raw_list.consume_raw_list_id,
    production_consume_raw_list.consume_raw_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    production_consume_raw_list.count,
    production_consume_raw_list.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = production_consume_raw_list.currency_id)) AS sum_currency_name,
    s.status_name,
    production_consume_raw_list.product_id,
    production_consume_raw_list.status_id,
    production_consume_raw_list.currency_id
   FROM ((production_consume_raw_list
     JOIN products p ON ((p.product_id = production_consume_raw_list.product_id)))
     JOIN status s ON ((s.status_id = production_consume_raw_list.status_id)));


ALTER TABLE production_consume_raw_list_view OWNER TO postgres;

--
-- TOC entry 327 (class 1259 OID 21302)
-- Name: production_consume_raws_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW production_consume_raws_view AS
 SELECT production_consume_raws.consume_raw_id,
    to_char(production_consume_raws.consume_raw_date, 'dd.MM.yyyy hh24:mi'::text) AS consume_raw_date,
    to_char(production_consume_raws.execution_date, 'dd.MM.yyyy hh24:mi'::text) AS execution_date,
    s.status_code,
    s.status_name,
    u1.user_name AS employee_name,
    u1.user_surname AS employee_surname,
    u1.user_phone AS employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u1.user_id)))) AS employee_position_name,
    u2.user_name AS stock_employee_name,
    u2.user_surname AS stock_employee_surname,
    u2.user_phone AS stock_employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u2.user_id)))) AS stock_employee_position_name,
    production_consume_raws.count,
    production_consume_raws.sum,
    c.currency_short_name AS currency_name,
    production_consume_raws.employee_id,
    production_consume_raws.user_id,
    production_consume_raws.status_id,
    production_consume_raws.currency_id
   FROM ((((production_consume_raws
     LEFT JOIN users u1 ON ((u1.user_id = production_consume_raws.user_id)))
     LEFT JOIN users u2 ON ((u2.user_id = production_consume_raws.employee_id)))
     LEFT JOIN status s ON ((s.status_id = production_consume_raws.status_id)))
     LEFT JOIN currencies c ON ((c.currency_id = production_consume_raws.currency_id)));


ALTER TABLE production_consume_raws_view OWNER TO postgres;

--
-- TOC entry 328 (class 1259 OID 21307)
-- Name: production_list; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE production_list (
    production_list_id integer NOT NULL,
    production_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE production_list OWNER TO postgres;

--
-- TOC entry 329 (class 1259 OID 21310)
-- Name: production_list_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW production_list_view AS
 SELECT production_list.production_list_id,
    production_list.production_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    production_list.count,
    production_list.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = production_list.currency_id)) AS sum_currency_name,
    s.status_name,
    production_list.product_id,
    production_list.status_id,
    production_list.currency_id
   FROM ((production_list
     JOIN products p ON ((p.product_id = production_list.product_id)))
     JOIN status s ON ((s.status_id = production_list.status_id)));


ALTER TABLE production_list_view OWNER TO postgres;

--
-- TOC entry 330 (class 1259 OID 21315)
-- Name: production_plan; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE production_plan (
    production_plan_id integer NOT NULL,
    production_plan_date timestamp without time zone NOT NULL,
    employee_id integer,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3) NOT NULL,
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE production_plan OWNER TO postgres;

--
-- TOC entry 331 (class 1259 OID 21318)
-- Name: production_plan_list; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE production_plan_list (
    production_plan_list_id integer NOT NULL,
    production_plan_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE production_plan_list OWNER TO postgres;

--
-- TOC entry 332 (class 1259 OID 21321)
-- Name: production_plan_list_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW production_plan_list_view AS
 SELECT production_plan_list.production_plan_list_id,
    production_plan_list.production_plan_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    production_plan_list.count,
    production_plan_list.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = production_plan_list.currency_id)) AS sum_currency_name,
    s.status_name,
    production_plan_list.product_id,
    production_plan_list.status_id,
    production_plan_list.currency_id
   FROM ((production_plan_list
     JOIN products p ON ((p.product_id = production_plan_list.product_id)))
     JOIN status s ON ((s.status_id = production_plan_list.status_id)));


ALTER TABLE production_plan_list_view OWNER TO postgres;

--
-- TOC entry 333 (class 1259 OID 21326)
-- Name: production_plan_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW production_plan_view AS
 SELECT production_plan.production_plan_id,
    to_char(production_plan.production_plan_date, 'dd.MM.yyyy hh24:mi'::text) AS production_plan_date,
    production_plan.count,
    production_plan.sum,
    c.currency_short_name AS currency_name,
    s.status_name,
    e.user_name,
    e.user_surname,
    e.user_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = e.position_id)) AS position_name,
    production_plan.employee_id,
    production_plan.status_id,
    production_plan.currency_id
   FROM (((production_plan
     JOIN employees_view e ON ((e.user_id = production_plan.employee_id)))
     JOIN currencies c ON ((c.currency_id = production_plan.currency_id)))
     JOIN status s ON ((s.status_id = production_plan.status_id)));


ALTER TABLE production_plan_view OWNER TO postgres;

--
-- TOC entry 335 (class 1259 OID 21342)
-- Name: production_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW production_view AS
 SELECT production.production_id,
    to_char((production.production_date)::timestamp with time zone, 'dd.MM.yyyy'::text) AS production_date,
    to_char((production.expiry_date)::timestamp with time zone, 'dd.MM.yyyy'::text) AS expiry_date,
    to_char(('2001-09-28'::date + (production.session_start)::time with time zone), 'hh24:mi'::text) AS session_start,
    to_char(('2001-09-28'::date + (production.session_end)::time with time zone), 'hh24:mi'::text) AS session_end
   FROM production;


ALTER TABLE production_view OWNER TO postgres;

--
-- TOC entry 336 (class 1259 OID 21346)
-- Name: products_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW products_view AS
 SELECT products.product_id,
    products.product_name,
    products.price,
    cur.currency_short_name AS currency,
    products.volume,
    m.measure_short_name AS measure_name,
    p.product_type_short_name AS product_type_name,
    products.shelf_life,
    c.company_name,
    products.company_id,
    products.measure_id,
    products.product_type_id,
    products.currency_id
   FROM ((((products
     JOIN companies c ON ((c.company_id = products.company_id)))
     JOIN measures m ON ((m.measure_id = products.measure_id)))
     JOIN product_type p ON ((p.product_type_id = products.product_type_id)))
     JOIN currencies cur ON ((cur.currency_id = products.currency_id)))
  ORDER BY products.product_name;


ALTER TABLE products_view OWNER TO postgres;

--
-- TOC entry 337 (class 1259 OID 21351)
-- Name: purveyors_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW purveyors_view AS
 SELECT users.user_id,
    users.user_name,
    users.user_surname,
    users.user_phone,
    ( SELECT locations.country_name
           FROM locations
          WHERE (locations.location_id = purveyors.location_id)) AS country_name,
    ( SELECT locations.region_name
           FROM locations
          WHERE (locations.location_id = purveyors.location_id)) AS region_name,
    ( SELECT locations.city_name
           FROM locations
          WHERE (locations.location_id = purveyors.location_id)) AS city_name,
    users.user_address,
    purveyors.company_name,
    ( SELECT roles.role_name
           FROM roles
          WHERE (roles.role_id = users.role_id)) AS role_name,
    users.password,
    users.user_email,
    users.activated,
    users.role_id,
    purveyors.location_id
   FROM (purveyors
     JOIN users ON ((users.user_id = purveyors.user_id)));


ALTER TABLE purveyors_view OWNER TO postgres;

--
-- TOC entry 416 (class 1259 OID 34879)
-- Name: receipt_other_stocks_list; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE receipt_other_stocks_list (
    receipt_other_stocks_list_id integer NOT NULL,
    receipt_other_stocks_id integer NOT NULL,
    other_stocks_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE receipt_other_stocks_list OWNER TO postgres;

--
-- TOC entry 424 (class 1259 OID 34920)
-- Name: receipt_other_stocks_list_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW receipt_other_stocks_list_view AS
 SELECT receipt_other_stocks_list.receipt_other_stocks_list_id,
    receipt_other_stocks_list.receipt_other_stocks_id,
    p.other_stocks_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    receipt_other_stocks_list.count,
    receipt_other_stocks_list.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = receipt_other_stocks_list.currency_id)) AS sum_currency_name,
    s.status_name,
    receipt_other_stocks_list.other_stocks_id,
    receipt_other_stocks_list.status_id,
    receipt_other_stocks_list.currency_id
   FROM ((receipt_other_stocks_list
     JOIN other_stocks p ON ((p.other_stocks_id = receipt_other_stocks_list.other_stocks_id)))
     JOIN status s ON ((s.status_id = receipt_other_stocks_list.status_id)));


ALTER TABLE receipt_other_stocks_list_view OWNER TO postgres;

--
-- TOC entry 425 (class 1259 OID 34925)
-- Name: receipt_other_stocks_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW receipt_other_stocks_view AS
 SELECT receipt_other_stocks.receipt_other_stocks_id,
    to_char(receipt_other_stocks.receipt_other_stocks_date, 'dd.MM.yyyy hh24:mm'::text) AS receipt_other_stocks_date,
    to_char(receipt_other_stocks.execution_date, 'dd.MM.yyyy hh24:mm'::text) AS execution_date,
    s.status_code,
    s.status_name,
    u1.user_name AS employee_name,
    u1.user_surname AS employee_surname,
    u1.user_phone AS employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u1.user_id)))) AS employee_position_name,
    u2.user_name AS stock_employee_name,
    u2.user_surname AS stock_employee_surname,
    u2.user_phone AS stock_employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u2.user_id)))) AS stock_employee_position_name,
    receipt_other_stocks.count,
    receipt_other_stocks.sum,
    c.currency_short_name AS currency_name,
    receipt_other_stocks.employee_id,
    receipt_other_stocks.user_id,
    receipt_other_stocks.status_id,
    receipt_other_stocks.currency_id
   FROM ((((receipt_other_stocks
     LEFT JOIN users u1 ON ((u1.user_id = receipt_other_stocks.user_id)))
     LEFT JOIN users u2 ON ((u2.user_id = receipt_other_stocks.employee_id)))
     LEFT JOIN status s ON ((s.status_id = receipt_other_stocks.status_id)))
     LEFT JOIN currencies c ON ((c.currency_id = receipt_other_stocks.currency_id)));


ALTER TABLE receipt_other_stocks_view OWNER TO postgres;

--
-- TOC entry 338 (class 1259 OID 21356)
-- Name: receipt_product_list; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE receipt_product_list (
    receipt_product_list_id integer NOT NULL,
    receipt_product_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE receipt_product_list OWNER TO postgres;

--
-- TOC entry 339 (class 1259 OID 21359)
-- Name: receipt_product_list_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW receipt_product_list_view AS
 SELECT receipt_product_list.receipt_product_list_id,
    receipt_product_list.receipt_product_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    receipt_product_list.count,
    receipt_product_list.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = receipt_product_list.currency_id)) AS sum_currency_name,
    s.status_name,
    receipt_product_list.product_id,
    receipt_product_list.status_id,
    receipt_product_list.currency_id
   FROM ((receipt_product_list
     JOIN products p ON ((p.product_id = receipt_product_list.product_id)))
     JOIN status s ON ((s.status_id = receipt_product_list.status_id)));


ALTER TABLE receipt_product_list_view OWNER TO postgres;

--
-- TOC entry 341 (class 1259 OID 21367)
-- Name: receipt_products_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW receipt_products_view AS
 SELECT receipt_products.receipt_product_id,
    to_char(receipt_products.receipt_product_date, 'dd.MM.yyyy hh24:mi'::text) AS receipt_product_date,
    to_char(receipt_products.execution_date, 'dd.MM.yyyy hh24:mi'::text) AS execution_date,
    s.status_code,
    s.status_name,
    u1.user_name AS employee_name,
    u1.user_surname AS employee_surname,
    u1.user_phone AS employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u1.user_id)))) AS employee_position_name,
    u2.user_name AS stock_employee_name,
    u2.user_surname AS stock_employee_surname,
    u2.user_phone AS stock_employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u2.user_id)))) AS stock_employee_position_name,
    receipt_products.count,
    receipt_products.sum,
    c.currency_short_name AS currency_name,
    receipt_products.employee_id,
    receipt_products.user_id,
    receipt_products.status_id,
    receipt_products.currency_id
   FROM ((((receipt_products
     LEFT JOIN users u1 ON ((u1.user_id = receipt_products.user_id)))
     LEFT JOIN users u2 ON ((u2.user_id = receipt_products.employee_id)))
     LEFT JOIN status s ON ((s.status_id = receipt_products.status_id)))
     LEFT JOIN currencies c ON ((c.currency_id = receipt_products.currency_id)));


ALTER TABLE receipt_products_view OWNER TO postgres;

--
-- TOC entry 342 (class 1259 OID 21372)
-- Name: refunds; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE refunds (
    refund_id integer NOT NULL,
    refund_date timestamp without time zone NOT NULL,
    refund_value numeric(20,3) NOT NULL,
    user_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE refunds OWNER TO postgres;

--
-- TOC entry 343 (class 1259 OID 21375)
-- Name: refunds_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW refunds_view AS
 SELECT refunds.refund_id,
    to_char(refunds.refund_date, 'dd.MM.yyyy hh24:mi'::text) AS refund_date,
    refunds.refund_value,
    c.currency_short_name AS currency_name,
    refunds.user_id,
    refunds.currency_id
   FROM (refunds
     JOIN currencies c ON ((c.currency_id = refunds.currency_id)));


ALTER TABLE refunds_view OWNER TO postgres;

--
-- TOC entry 344 (class 1259 OID 21379)
-- Name: relation_type; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE relation_type (
    relation_type_id integer NOT NULL,
    relation_name character varying(30) NOT NULL,
    comment character varying(100)
);


ALTER TABLE relation_type OWNER TO postgres;

--
-- TOC entry 345 (class 1259 OID 21382)
-- Name: relation_type_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW relation_type_view AS
 SELECT relation_type.relation_type_id,
    relation_type.relation_name,
    relation_type.comment
   FROM relation_type;


ALTER TABLE relation_type_view OWNER TO postgres;

--
-- TOC entry 346 (class 1259 OID 21386)
-- Name: relations; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE relations (
    relation_id integer NOT NULL,
    user_id_1 integer NOT NULL,
    user_id_2 integer NOT NULL,
    relation_type_id integer NOT NULL
);


ALTER TABLE relations OWNER TO postgres;

--
-- TOC entry 347 (class 1259 OID 21389)
-- Name: relations_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW relations_view AS
 SELECT relations.relation_id,
    u1.user_name AS employee_name,
    u1.user_surname AS employee_surname,
    u1.user_phone AS employee_phone,
    rt.relation_name,
    u2.user_name,
    u2.user_surname,
    u2.user_phone,
    relations.user_id_1,
    relations.user_id_2,
    relations.relation_type_id
   FROM (((relations
     JOIN users u1 ON ((u1.user_id = relations.user_id_1)))
     JOIN users u2 ON ((u2.user_id = relations.user_id_2)))
     JOIN relation_type rt ON ((rt.relation_type_id = relations.relation_type_id)));


ALTER TABLE relations_view OWNER TO postgres;

--
-- TOC entry 348 (class 1259 OID 21394)
-- Name: return_list; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE return_list (
    return_list_id integer NOT NULL,
    return_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE return_list OWNER TO postgres;

--
-- TOC entry 349 (class 1259 OID 21397)
-- Name: return_list_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW return_list_view AS
 SELECT return_list.return_list_id,
    return_list.return_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    return_list.count,
    return_list.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = return_list.currency_id)) AS sum_currency_name,
    s.status_name,
    return_list.product_id,
    return_list.status_id,
    return_list.currency_id
   FROM ((return_list
     JOIN products p ON ((p.product_id = return_list.product_id)))
     JOIN status s ON ((s.status_id = return_list.status_id)));


ALTER TABLE return_list_view OWNER TO postgres;

--
-- TOC entry 351 (class 1259 OID 21405)
-- Name: returns_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW returns_view AS
 SELECT returns.return_id,
    to_char(returns.return_date, 'dd.MM.yyyy hh24:mi'::text) AS return_date,
    to_char(returns.execution_date, 'dd.MM.yyyy hh24:mi'::text) AS execution_date,
    s.status_code,
    s.status_name,
    u1.user_name AS client_name,
    u1.user_surname AS client_surname,
    u1.user_phone AS client_phone,
    u1.user_address AS clinet_address,
    ( SELECT clients.firm
           FROM clients
          WHERE (clients.user_id = u1.user_id)) AS client_firm,
    u2.user_name AS employee_name,
    u2.user_surname AS employee_surname,
    u2.user_phone AS employee_phone,
    returns.count,
    returns.sum,
    c.currency_short_name AS currency_name,
    returns.employee_id,
    returns.user_id,
    returns.status_id,
    returns.currency_id
   FROM ((((returns
     LEFT JOIN users u1 ON ((u1.user_id = returns.user_id)))
     LEFT JOIN users u2 ON ((u2.user_id = returns.employee_id)))
     LEFT JOIN status s ON ((s.status_id = returns.status_id)))
     LEFT JOIN currencies c ON ((c.currency_id = returns.currency_id)));


ALTER TABLE returns_view OWNER TO postgres;

--
-- TOC entry 352 (class 1259 OID 21410)
-- Name: roles_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW roles_view AS
 SELECT roles.role_id,
    roles.role_code,
    roles.role_name,
    roles.comment
   FROM roles;


ALTER TABLE roles_view OWNER TO postgres;

--
-- TOC entry 353 (class 1259 OID 21414)
-- Name: salaries; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE salaries (
    salary_id integer NOT NULL,
    user_id integer NOT NULL,
    salary_value numeric(20,3) NOT NULL,
    currency_id integer NOT NULL,
    salary_type_id integer NOT NULL,
    salary_date timestamp without time zone NOT NULL,
    salary_bonus boolean
);


ALTER TABLE salaries OWNER TO postgres;

--
-- TOC entry 354 (class 1259 OID 21417)
-- Name: salary_type; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE salary_type (
    salary_type_id integer NOT NULL,
    salary_type_code character varying(15) NOT NULL,
    salary_type_name character varying(30) NOT NULL
);


ALTER TABLE salary_type OWNER TO postgres;

--
-- TOC entry 355 (class 1259 OID 21420)
-- Name: salaries_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW salaries_view AS
 SELECT salaries.salary_id,
    salaries.user_id,
    u.user_name,
    u.user_surname,
    u.user_phone,
    to_char(salaries.salary_date, 'dd.MM.yyyy hh24:mi'::text) AS salary_date,
    salaries.salary_value,
    c.currency_short_name AS currency_name,
    s.salary_type_name,
    salaries.currency_id,
    salaries.salary_type_id,
    salaries.salary_bonus
   FROM (((salaries
     JOIN users u ON ((u.user_id = salaries.user_id)))
     JOIN currencies c ON ((c.currency_id = salaries.currency_id)))
     JOIN salary_type s ON ((s.salary_type_id = salaries.salary_type_id)));


ALTER TABLE salaries_view OWNER TO postgres;

--
-- TOC entry 356 (class 1259 OID 21425)
-- Name: salary_type_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW salary_type_view AS
 SELECT salary_type.salary_type_id,
    salary_type.salary_type_code,
    salary_type.salary_type_name
   FROM salary_type;


ALTER TABLE salary_type_view OWNER TO postgres;

--
-- TOC entry 357 (class 1259 OID 21429)
-- Name: shareholders; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE shareholders (
    user_id integer NOT NULL,
    count_of_stock numeric(20,3),
    informaton character varying(100)
);


ALTER TABLE shareholders OWNER TO postgres;

--
-- TOC entry 358 (class 1259 OID 21432)
-- Name: shareholders_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW shareholders_view AS
 SELECT shareholders.user_id,
    users.user_name,
    users.user_surname,
    users.user_phone,
    users.user_address,
    shareholders.count_of_stock,
    shareholders.informaton
   FROM (shareholders
     JOIN users ON ((users.user_id = shareholders.user_id)));


ALTER TABLE shareholders_view OWNER TO postgres;

--
-- TOC entry 359 (class 1259 OID 21436)
-- Name: specification_list; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE specification_list (
    specification_list_id integer NOT NULL,
    specification_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(20,5) NOT NULL
);


ALTER TABLE specification_list OWNER TO postgres;

--
-- TOC entry 360 (class 1259 OID 21439)
-- Name: specification_list_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW specification_list_view AS
 SELECT specification_list.specification_list_id,
    specification_list.specification_id,
    p.product_name,
    specification_list.count,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    specification_list.product_id
   FROM (specification_list
     JOIN products p ON ((p.product_id = specification_list.product_id)));


ALTER TABLE specification_list_view OWNER TO postgres;

--
-- TOC entry 361 (class 1259 OID 21443)
-- Name: specifications; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE specifications (
    specification_id integer NOT NULL,
    product_id integer NOT NULL,
    sum numeric(20,3) NOT NULL,
    currency_id integer NOT NULL,
    employee_id integer NOT NULL,
    specification_date timestamp without time zone NOT NULL
);


ALTER TABLE specifications OWNER TO postgres;

--
-- TOC entry 362 (class 1259 OID 21446)
-- Name: specifications_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW specifications_view AS
 SELECT specifications.specification_id,
    to_char(specifications.specification_date, 'dd.MM.yyyy hh24:mi'::text) AS specification_date,
    p.product_name,
    specifications.sum,
    c.currency_short_name AS currency_name,
    u.user_name AS employee_name,
    u.user_surname AS employee_surname,
    u.user_phone AS employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u.user_id)))) AS employee_position_name,
    specifications.product_id,
    specifications.currency_id,
    specifications.employee_id
   FROM (((specifications
     LEFT JOIN products p ON ((p.product_id = specifications.product_id)))
     LEFT JOIN users u ON ((u.user_id = specifications.employee_id)))
     LEFT JOIN currencies c ON ((c.currency_id = specifications.currency_id)));


ALTER TABLE specifications_view OWNER TO postgres;

--
-- TOC entry 364 (class 1259 OID 21454)
-- Name: spoilage_list; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE spoilage_list (
    spoilage_list_id integer NOT NULL,
    spoilage_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE spoilage_list OWNER TO postgres;

--
-- TOC entry 365 (class 1259 OID 21457)
-- Name: spoilage_list_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW spoilage_list_view AS
 SELECT spoilage_list.spoilage_list_id,
    spoilage_list.spoilage_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    spoilage_list.count,
    spoilage_list.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = spoilage_list.currency_id)) AS sum_currency_name,
    s.status_name,
    spoilage_list.product_id,
    spoilage_list.status_id,
    spoilage_list.currency_id
   FROM ((spoilage_list
     JOIN products p ON ((p.product_id = spoilage_list.product_id)))
     JOIN status s ON ((s.status_id = spoilage_list.status_id)));


ALTER TABLE spoilage_list_view OWNER TO postgres;

--
-- TOC entry 366 (class 1259 OID 21462)
-- Name: spoilage_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW spoilage_view AS
 SELECT spoilage.spoilage_id,
    to_char(spoilage.spoilage_date, 'dd.MM.yyyy hh24:mi'::text) AS spoilage_date,
    spoilage.count,
    spoilage.sum,
    c.currency_short_name AS currency_name,
    s.status_name,
    e.user_name,
    e.user_surname,
    e.user_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = e.position_id)) AS position_name,
    spoilage.employee_id,
    spoilage.status_id,
    spoilage.currency_id
   FROM (((spoilage
     LEFT JOIN employees_view e ON ((e.user_id = spoilage.employee_id)))
     LEFT JOIN currencies c ON ((c.currency_id = spoilage.currency_id)))
     LEFT JOIN status s ON ((s.status_id = spoilage.status_id)));


ALTER TABLE spoilage_view OWNER TO postgres;

--
-- TOC entry 367 (class 1259 OID 21467)
-- Name: state; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE state (
    state_id integer NOT NULL,
    universal_id integer NOT NULL,
    status_id integer NOT NULL,
    last_change timestamp with time zone
);


ALTER TABLE state OWNER TO postgres;

--
-- TOC entry 368 (class 1259 OID 21470)
-- Name: state_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW state_view AS
 SELECT state.state_id,
    state.universal_id,
    state.status_id,
    to_char(state.last_change, 'dd.MM.yyyy hh24:mi'::text) AS last_change
   FROM state;


ALTER TABLE state_view OWNER TO postgres;

--
-- TOC entry 369 (class 1259 OID 21474)
-- Name: status_rule; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE status_rule (
    status_rule_id integer NOT NULL,
    operation character varying(50) NOT NULL,
    status_id integer NOT NULL
);


ALTER TABLE status_rule OWNER TO postgres;

--
-- TOC entry 370 (class 1259 OID 21477)
-- Name: status_rule_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW status_rule_view AS
 SELECT status_rule.status_rule_id,
    status_rule.operation,
    s.status_name,
    status_rule.status_id
   FROM (status_rule
     JOIN status s ON ((s.status_id = status_rule.status_id)));


ALTER TABLE status_rule_view OWNER TO postgres;

--
-- TOC entry 371 (class 1259 OID 21481)
-- Name: status_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW status_view AS
 SELECT status.status_id,
    status.status_code,
    status.status_name,
    status.comment
   FROM status;


ALTER TABLE status_view OWNER TO postgres;

--
-- TOC entry 372 (class 1259 OID 21485)
-- Name: stock; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE stock (
    stock_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL,
    warehouse_id integer
);


ALTER TABLE stock OWNER TO postgres;

--
-- TOC entry 373 (class 1259 OID 21488)
-- Name: stock_history; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE stock_history (
    stock_id integer NOT NULL,
    product_id integer,
    count numeric(15,5),
    sum numeric(20,3),
    status_id integer,
    currency_id integer,
    warehouse_id integer,
    history_date timestamp without time zone
);


ALTER TABLE stock_history OWNER TO postgres;

--
-- TOC entry 409 (class 1259 OID 26703)
-- Name: stock_history_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW stock_history_view AS
 SELECT stock_history.stock_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    stock_history.count,
    stock_history.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = stock_history.currency_id)) AS sum_currency_name,
    w.warehouse_name,
    ( SELECT subaccounts.subaccount_number
           FROM subaccounts
          WHERE (subaccounts.subaccount_id = w.subaccount_id)) AS subaccount_number,
    s.status_name,
    stock_history.product_id,
    stock_history.status_id,
    stock_history.currency_id,
    stock_history.warehouse_id,
    to_char(stock_history.history_date, 'dd.MM.yyyy hh24:mi'::text) AS history_date
   FROM (((stock_history
     LEFT JOIN products p ON ((p.product_id = stock_history.product_id)))
     LEFT JOIN status s ON ((s.status_id = stock_history.status_id)))
     LEFT JOIN warehouse w ON ((w.warehouse_id = stock_history.warehouse_id)));


ALTER TABLE stock_history_view OWNER TO postgres;

--
-- TOC entry 374 (class 1259 OID 21496)
-- Name: stock_transfer_list; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE stock_transfer_list (
    stock_transfer_list_id integer NOT NULL,
    stock_transfer_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE stock_transfer_list OWNER TO postgres;

--
-- TOC entry 375 (class 1259 OID 21499)
-- Name: stock_transfer_list_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW stock_transfer_list_view AS
 SELECT stock_transfer_list.stock_transfer_list_id,
    stock_transfer_list.stock_transfer_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    stock_transfer_list.count,
    stock_transfer_list.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = stock_transfer_list.currency_id)) AS sum_currency_name,
    s.status_name,
    stock_transfer_list.product_id,
    stock_transfer_list.status_id,
    stock_transfer_list.currency_id
   FROM ((stock_transfer_list
     JOIN products p ON ((p.product_id = stock_transfer_list.product_id)))
     JOIN status s ON ((s.status_id = stock_transfer_list.status_id)));


ALTER TABLE stock_transfer_list_view OWNER TO postgres;

--
-- TOC entry 377 (class 1259 OID 21507)
-- Name: stock_transfers_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW stock_transfers_view AS
 SELECT stock_transfers.stock_transfer_id,
    to_char(stock_transfers.stock_transfer_date, 'dd.MM.yyyy hh24:mi'::text) AS stock_transfer_date,
    to_char(stock_transfers.execution_date, 'dd.MM.yyyy hh24:mi'::text) AS execution_date,
    s.status_code,
    s.status_name,
    u1.user_name AS employee_name,
    u1.user_surname AS employee_surname,
    u1.user_phone AS employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u1.user_id)))) AS employee_position_name,
    u2.user_name AS stock_employee_name,
    u2.user_surname AS stock_employee_surname,
    u2.user_phone AS stock_employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u2.user_id)))) AS stock_employee_position_name,
    stock_transfers.count,
    stock_transfers.sum,
    c.currency_short_name AS currency_name,
    stock_transfers.employee_id,
    stock_transfers.user_id,
    stock_transfers.status_id,
    stock_transfers.currency_id
   FROM ((((stock_transfers
     LEFT JOIN users u1 ON ((u1.user_id = stock_transfers.user_id)))
     LEFT JOIN users u2 ON ((u2.user_id = stock_transfers.employee_id)))
     LEFT JOIN status s ON ((s.status_id = stock_transfers.status_id)))
     LEFT JOIN currencies c ON ((c.currency_id = stock_transfers.currency_id)));


ALTER TABLE stock_transfers_view OWNER TO postgres;

--
-- TOC entry 378 (class 1259 OID 21512)
-- Name: stock_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW stock_view AS
 SELECT stock.stock_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    stock.count,
    stock.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = stock.currency_id)) AS sum_currency_name,
    w.warehouse_name,
    ( SELECT subaccounts.subaccount_number
           FROM subaccounts
          WHERE (subaccounts.subaccount_id = w.subaccount_id)) AS subaccount_number,
    s.status_name,
    stock.product_id,
    stock.status_id,
    stock.currency_id,
    stock.warehouse_id
   FROM (((stock
     JOIN products p ON ((p.product_id = stock.product_id)))
     JOIN status s ON ((s.status_id = stock.status_id)))
     JOIN warehouse w ON ((w.warehouse_id = stock.warehouse_id)))
  ORDER BY p.product_name;


ALTER TABLE stock_view OWNER TO postgres;

--
-- TOC entry 379 (class 1259 OID 21517)
-- Name: subaccount_history; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE subaccount_history (
    subaccount_history_id integer NOT NULL,
    subaccount_id integer NOT NULL,
    start_balance numeric(20,3) NOT NULL,
    current_balance numeric(20,3) NOT NULL,
    from_date date,
    till_date date
);


ALTER TABLE subaccount_history OWNER TO postgres;

--
-- TOC entry 410 (class 1259 OID 26708)
-- Name: subaccount_history_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW subaccount_history_view AS
 SELECT subaccount_history.subaccount_history_id,
    subaccount_history.subaccount_id,
    subaccount_history.start_balance,
    subaccount_history.current_balance,
    to_char((subaccount_history.from_date)::timestamp with time zone, 'dd.MM.yyyy'::text) AS from_date,
    to_char((subaccount_history.till_date)::timestamp with time zone, 'dd.MM.yyyy'::text) AS till_date
   FROM subaccount_history;


ALTER TABLE subaccount_history_view OWNER TO postgres;

--
-- TOC entry 380 (class 1259 OID 21524)
-- Name: subaccounts_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW subaccounts_view AS
 SELECT subaccounts.subaccount_id,
    a.account_id,
    a.account_number,
    subaccounts.subaccount_number,
    subaccounts.start_balance,
    subaccounts.current_balance,
    c.currency_short_name AS currency_name,
    s.status_name,
    subaccounts.currency_id,
    subaccounts.status_id,
    to_char((subaccounts.date_opened)::timestamp with time zone, 'dd.MM.yyyy'::text) AS date_opened,
    to_char((subaccounts.date_closed)::timestamp with time zone, 'dd.MM.yyyy'::text) AS date_closed,
    subaccounts.details
   FROM (((subaccounts
     JOIN accounts a ON ((a.account_id = subaccounts.account_id)))
     JOIN currencies c ON ((c.currency_id = subaccounts.currency_id)))
     JOIN status s ON ((s.status_id = subaccounts.status_id)));


ALTER TABLE subaccounts_view OWNER TO postgres;

--
-- TOC entry 381 (class 1259 OID 21529)
-- Name: taxes; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE taxes (
    tax_id integer NOT NULL,
    tax_name character(100) NOT NULL,
    tax_code character varying(15) NOT NULL,
    fixed_value numeric(20,3),
    percent_value integer,
    formula_value character varying(100)
);


ALTER TABLE taxes OWNER TO postgres;

--
-- TOC entry 382 (class 1259 OID 21532)
-- Name: taxes_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW taxes_view AS
 SELECT taxes.tax_id,
    taxes.tax_name,
    taxes.tax_code,
    taxes.fixed_value,
    taxes.percent_value,
    taxes.formula_value
   FROM taxes;


ALTER TABLE taxes_view OWNER TO postgres;

--
-- TOC entry 383 (class 1259 OID 21536)
-- Name: timesheet; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE timesheet (
    timesheet_id integer NOT NULL,
    salary_id integer NOT NULL,
    worked_time numeric(4,2) NOT NULL,
    timesheet_date date NOT NULL
);


ALTER TABLE timesheet OWNER TO postgres;

--
-- TOC entry 384 (class 1259 OID 21539)
-- Name: timesheet_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW timesheet_view AS
 SELECT timesheet.timesheet_id,
    s.user_name,
    s.user_surname,
    s.user_phone,
    to_char((timesheet.timesheet_date)::timestamp with time zone, 'dd.MM.yyyy'::text) AS timesheet_date,
    timesheet.worked_time,
    timesheet.salary_id
   FROM (timesheet
     JOIN salaries_view s ON ((s.salary_id = timesheet.salary_id)));


ALTER TABLE timesheet_view OWNER TO postgres;

--
-- TOC entry 429 (class 1259 OID 52479)
-- Name: transport_history; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE transport_history (
    transport_history_id integer NOT NULL,
    transport_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL,
    from_date date,
    till_date date
);


ALTER TABLE transport_history OWNER TO postgres;

--
-- TOC entry 430 (class 1259 OID 52484)
-- Name: transport_history_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW transport_history_view AS
 SELECT transport_history.transport_history_id,
    transport_history.transport_id,
    transport_history.product_id,
    transport_history.count,
    transport_history.sum,
    transport_history.status_id,
    transport_history.currency_id,
    transport_history.from_date,
    transport_history.till_date
   FROM transport_history;


ALTER TABLE transport_history_view OWNER TO postgres;

--
-- TOC entry 385 (class 1259 OID 21543)
-- Name: transport_list; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE transport_list (
    transport_list_id integer NOT NULL,
    transport_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE transport_list OWNER TO postgres;

--
-- TOC entry 386 (class 1259 OID 21546)
-- Name: transport_list_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW transport_list_view AS
 SELECT transport_list.transport_list_id,
    transport_list.transport_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    transport_list.count,
    transport_list.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = transport_list.currency_id)) AS sum_currency_name,
    s.status_name,
    transport_list.product_id,
    transport_list.status_id,
    transport_list.currency_id
   FROM ((transport_list
     JOIN products p ON ((p.product_id = transport_list.product_id)))
     JOIN status s ON ((s.status_id = transport_list.status_id)));


ALTER TABLE transport_list_view OWNER TO postgres;

--
-- TOC entry 387 (class 1259 OID 21551)
-- Name: transports; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE transports (
    transport_id integer NOT NULL,
    user_id integer,
    transport_date timestamp without time zone,
    execution_date timestamp(0) without time zone,
    employee_id integer NOT NULL,
    count numeric(15,5),
    sum numeric(20,3),
    status_id integer,
    currency_id integer
);


ALTER TABLE transports OWNER TO postgres;

--
-- TOC entry 388 (class 1259 OID 21554)
-- Name: transports_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW transports_view AS
 SELECT transports.transport_id,
    to_char(transports.transport_date, 'dd.MM.yyyy hh24:mi'::text) AS transport_date,
    to_char(transports.execution_date, 'dd.MM.yyyy hh24:mi'::text) AS execution_date,
    s.status_code,
    s.status_name,
    u1.user_name,
    u1.user_surname,
    u1.user_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u1.user_id)))) AS user_position_name,
    u2.user_name AS employee_name,
    u2.user_surname AS employee_surname,
    u2.user_phone AS employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u2.user_id)))) AS employee_position_name,
    transports.count,
    transports.sum,
    c.currency_short_name AS currency_name,
    transports.employee_id,
    transports.user_id,
    transports.status_id,
    transports.currency_id
   FROM ((((transports
     LEFT JOIN users u1 ON ((u1.user_id = transports.user_id)))
     LEFT JOIN users u2 ON ((u2.user_id = transports.employee_id)))
     LEFT JOIN status s ON ((s.status_id = transports.status_id)))
     LEFT JOIN currencies c ON ((c.currency_id = transports.currency_id)));


ALTER TABLE transports_view OWNER TO postgres;

--
-- TOC entry 428 (class 1259 OID 44274)
-- Name: user_branch_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW user_branch_view AS
 SELECT users.user_id,
    users.user_email,
    users.user_name,
    users.user_surname,
    users.user_phone,
    users.user_address,
    users.role_id,
    users.password,
    users.activated,
    company_employee.company_employee_id,
    company_employee.company_id,
    company_employee.employee_id,
    company_employee.branch_id
   FROM (users
     LEFT JOIN company_employee ON ((company_employee.employee_id = users.user_id)));


ALTER TABLE user_branch_view OWNER TO postgres;

--
-- TOC entry 389 (class 1259 OID 21559)
-- Name: users_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW users_view AS
 SELECT users.user_id,
    users.user_email,
    users.user_name,
    users.user_surname,
    users.user_phone,
    users.user_address,
    r.role_name,
    users.password,
    users.activated,
    users.role_id
   FROM (users
     JOIN roles r ON ((r.role_id = users.role_id)));


ALTER TABLE users_view OWNER TO postgres;

--
-- TOC entry 390 (class 1259 OID 21563)
-- Name: warehouse_employee; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE warehouse_employee (
    warehouse_employee_id integer NOT NULL,
    warehouse_id integer NOT NULL,
    employee_id integer NOT NULL
);


ALTER TABLE warehouse_employee OWNER TO postgres;

--
-- TOC entry 391 (class 1259 OID 21566)
-- Name: warehouse_employee_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW warehouse_employee_view AS
 SELECT warehouse_employee.warehouse_employee_id,
    u.user_name,
    u.user_surname,
    u.user_phone,
    ( SELECT roles.role_name
           FROM roles
          WHERE (roles.role_id = u.role_id)) AS role_name,
    w.warehouse_name,
    ( SELECT subaccounts.subaccount_number
           FROM subaccounts
          WHERE (subaccounts.subaccount_id = w.subaccount_id)) AS subaccount_number,
    warehouse_employee.warehouse_id,
    warehouse_employee.employee_id
   FROM ((warehouse_employee
     JOIN warehouse w ON ((w.warehouse_id = warehouse_employee.warehouse_id)))
     JOIN users u ON ((u.user_id = warehouse_employee.employee_id)));


ALTER TABLE warehouse_employee_view OWNER TO postgres;

--
-- TOC entry 392 (class 1259 OID 21571)
-- Name: warehouse_type; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE warehouse_type (
    warehouse_type_id integer NOT NULL,
    warehouse_type_code character varying(20) NOT NULL,
    warehouse_type_purpose character varying(60),
    warehouse_type_name character varying(60) NOT NULL
);


ALTER TABLE warehouse_type OWNER TO postgres;

--
-- TOC entry 393 (class 1259 OID 21574)
-- Name: warehouse_type_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW warehouse_type_view AS
 SELECT warehouse_type.warehouse_type_id,
    warehouse_type.warehouse_type_code,
    warehouse_type.warehouse_type_purpose,
    warehouse_type.warehouse_type_name
   FROM warehouse_type;


ALTER TABLE warehouse_type_view OWNER TO postgres;

--
-- TOC entry 394 (class 1259 OID 21578)
-- Name: warehouse_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW warehouse_view AS
 SELECT warehouse.warehouse_id,
    warehouse.warehouse_name,
    s.subaccount_number,
    wt.warehouse_type_name,
    warehouse.warehouse_address,
    warehouse.warehouse_phone,
    warehouse.warehouse_type_id,
    warehouse.subaccount_id
   FROM ((warehouse
     JOIN warehouse_type wt ON ((wt.warehouse_type_id = warehouse.warehouse_type_id)))
     JOIN subaccounts s ON ((s.subaccount_id = warehouse.subaccount_id)));


ALTER TABLE warehouse_view OWNER TO postgres;

--
-- TOC entry 396 (class 1259 OID 21586)
-- Name: withdrawals_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW withdrawals_view AS
 SELECT withdrawals.withdrawal_id,
    to_char(withdrawals.withdrawal_date, 'dd.MM.yyyy hh24:mi'::text) AS withdrawal_date,
    withdrawals.withdrawal_value,
    c.currency_short_name AS currency_name,
    u.user_name,
    u.user_surname,
    u.user_phone,
    st.status_name,
    a.account_number,
    s.subaccount_number,
    withdrawals.who,
    withdrawals.withdrawal_target,
    withdrawals.user_id,
    withdrawals.currency_id,
    withdrawals.subaccount_id,
    st.status_id,
    a.account_id,
    withdrawals.cashbox_account_id
   FROM (((((withdrawals
     LEFT JOIN users u ON ((u.user_id = withdrawals.user_id)))
     LEFT JOIN currencies c ON ((c.currency_id = withdrawals.currency_id)))
     LEFT JOIN status st ON ((st.status_id = withdrawals.status_id)))
     LEFT JOIN subaccounts s ON ((s.subaccount_id = withdrawals.subaccount_id)))
     LEFT JOIN accounts a ON ((a.account_id = withdrawals.account_id)));


ALTER TABLE withdrawals_view OWNER TO postgres;

--
-- TOC entry 397 (class 1259 OID 21591)
-- Name: write_off_list; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE write_off_list (
    write_off_list_id integer NOT NULL,
    write_off_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE write_off_list OWNER TO postgres;

--
-- TOC entry 398 (class 1259 OID 21594)
-- Name: write_off_list_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW write_off_list_view AS
 SELECT write_off_list.write_off_list_id,
    write_off_list.write_off_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    write_off_list.count,
    write_off_list.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = write_off_list.currency_id)) AS sum_currency_name,
    s.status_name,
    write_off_list.product_id,
    write_off_list.status_id,
    write_off_list.currency_id
   FROM ((write_off_list
     JOIN products p ON ((p.product_id = write_off_list.product_id)))
     JOIN status s ON ((s.status_id = write_off_list.status_id)));


ALTER TABLE write_off_list_view OWNER TO postgres;

--
-- TOC entry 399 (class 1259 OID 21599)
-- Name: write_off_raw_list; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE write_off_raw_list (
    write_off_raw_list_id integer NOT NULL,
    write_off_raw_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE write_off_raw_list OWNER TO postgres;

--
-- TOC entry 400 (class 1259 OID 21602)
-- Name: write_off_raw_list_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW write_off_raw_list_view AS
 SELECT write_off_raw_list.write_off_raw_list_id,
    write_off_raw_list.write_off_raw_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    write_off_raw_list.count,
    write_off_raw_list.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = write_off_raw_list.currency_id)) AS sum_currency_name,
    s.status_name,
    write_off_raw_list.product_id,
    write_off_raw_list.status_id,
    write_off_raw_list.currency_id
   FROM ((write_off_raw_list
     JOIN products p ON ((p.product_id = write_off_raw_list.product_id)))
     JOIN status s ON ((s.status_id = write_off_raw_list.status_id)));


ALTER TABLE write_off_raw_list_view OWNER TO postgres;

--
-- TOC entry 402 (class 1259 OID 21610)
-- Name: write_off_raws_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW write_off_raws_view AS
 SELECT write_off_raws.write_off_raw_id,
    to_char(write_off_raws.write_off_raw_date, 'dd.MM.yyyy hh24:mi'::text) AS write_off_raw_date,
    to_char(write_off_raws.execution_date, 'dd.MM.yyyy hh24:mi'::text) AS execution_date,
    s.status_code,
    s.status_name,
    u1.user_name AS employee_name,
    u1.user_surname AS employee_surname,
    u1.user_phone AS employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u1.user_id)))) AS employee_position_name,
    u2.user_name AS stock_employee_name,
    u2.user_surname AS stock_employee_surname,
    u2.user_phone AS stock_employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u2.user_id)))) AS stock_employee_position_name,
    write_off_raws.count,
    write_off_raws.sum,
    c.currency_short_name AS currency_name,
    write_off_raws.employee_id,
    write_off_raws.user_id,
    write_off_raws.status_id,
    write_off_raws.currency_id
   FROM ((((write_off_raws
     LEFT JOIN users u1 ON ((u1.user_id = write_off_raws.user_id)))
     LEFT JOIN users u2 ON ((u2.user_id = write_off_raws.employee_id)))
     LEFT JOIN status s ON ((s.status_id = write_off_raws.status_id)))
     LEFT JOIN currencies c ON ((c.currency_id = write_off_raws.currency_id)));


ALTER TABLE write_off_raws_view OWNER TO postgres;

--
-- TOC entry 404 (class 1259 OID 21618)
-- Name: write_offs_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW write_offs_view AS
 SELECT write_offs.write_off_id,
    to_char(write_offs.write_off_date, 'dd.MM.yyyy hh24:mi'::text) AS write_off_date,
    to_char(write_offs.execution_date, 'dd.MM.yyyy hh24:mi'::text) AS execution_date,
    s.status_code,
    s.status_name,
    u1.user_name AS client_name,
    u1.user_surname AS client_surname,
    u1.user_phone AS client_phone,
    u1.user_address AS clinet_address,
    ( SELECT clients.firm
           FROM clients
          WHERE (clients.user_id = u1.user_id)) AS client_firm,
    u2.user_name AS employee_name,
    u2.user_surname AS employee_surname,
    u2.user_phone AS employee_phone,
    write_offs.count,
    write_offs.sum,
    c.currency_short_name AS currency_name,
    write_offs.employee_id,
    write_offs.user_id,
    write_offs.status_id,
    write_offs.currency_id
   FROM ((((write_offs
     LEFT JOIN users u1 ON ((u1.user_id = write_offs.user_id)))
     LEFT JOIN users u2 ON ((u2.user_id = write_offs.employee_id)))
     LEFT JOIN status s ON ((s.status_id = write_offs.status_id)))
     LEFT JOIN currencies c ON ((c.currency_id = write_offs.currency_id)));


ALTER TABLE write_offs_view OWNER TO postgres;

--
-- TOC entry 2985 (class 2606 OID 21624)
-- Name: access_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY accesses
    ADD CONSTRAINT access_pkey PRIMARY KEY (access_id);


--
-- TOC entry 2989 (class 2606 OID 21626)
-- Name: account_history_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY account_history
    ADD CONSTRAINT account_history_pkey PRIMARY KEY (account_history_id);


--
-- TOC entry 2999 (class 2606 OID 21628)
-- Name: account_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY accounts
    ADD CONSTRAINT account_pkey PRIMARY KEY (account_id);


--
-- TOC entry 2991 (class 2606 OID 21630)
-- Name: account_type_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY account_type
    ADD CONSTRAINT account_type_pkey PRIMARY KEY (account_type_id);


--
-- TOC entry 2993 (class 2606 OID 21632)
-- Name: accountable_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY accountable
    ADD CONSTRAINT accountable_pkey PRIMARY KEY (employee_id);


--
-- TOC entry 2995 (class 2606 OID 21634)
-- Name: accountable_trancation_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY accountable_transaction
    ADD CONSTRAINT accountable_trancation_pkey PRIMARY KEY (accountable_transaction_id);


--
-- TOC entry 3001 (class 2606 OID 21636)
-- Name: amortize_group_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY amortize_group
    ADD CONSTRAINT amortize_group_pkey PRIMARY KEY (amortize_group_id);


--
-- TOC entry 3003 (class 2606 OID 21638)
-- Name: amortize_type_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY amortize_type
    ADD CONSTRAINT amortize_type_pkey PRIMARY KEY (amortize_type_id);


--
-- TOC entry 3005 (class 2606 OID 21640)
-- Name: balance_payment_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY balance_payment
    ADD CONSTRAINT balance_payment_pkey PRIMARY KEY (balance_payment_id);


--
-- TOC entry 3007 (class 2606 OID 21642)
-- Name: balance_payslip_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY balance_payslip
    ADD CONSTRAINT balance_payslip_pkey PRIMARY KEY (balance_payslip_id);


--
-- TOC entry 3013 (class 2606 OID 21644)
-- Name: balance_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY balances
    ADD CONSTRAINT balance_pkey PRIMARY KEY (balance_id);


--
-- TOC entry 3009 (class 2606 OID 21646)
-- Name: balance_refund_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY balance_refund
    ADD CONSTRAINT balance_refund_pkey PRIMARY KEY (balance_refund_id);


--
-- TOC entry 3011 (class 2606 OID 21648)
-- Name: balance_withdrawal_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY balance_withdrawal
    ADD CONSTRAINT balance_withdrawal_pkey PRIMARY KEY (balance_withdrawal_id);


--
-- TOC entry 3019 (class 2606 OID 21650)
-- Name: borrower_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY borrowers
    ADD CONSTRAINT borrower_pkey PRIMARY KEY (user_id);


--
-- TOC entry 3021 (class 2606 OID 21652)
-- Name: branch_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY branches
    ADD CONSTRAINT branch_pkey PRIMARY KEY (branch_id);


--
-- TOC entry 3025 (class 2606 OID 21654)
-- Name: cashbox_employee_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY cashbox_employee
    ADD CONSTRAINT cashbox_employee_pkey PRIMARY KEY (cashbox_employee_id);


--
-- TOC entry 3023 (class 2606 OID 21656)
-- Name: cashbox_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY cashbox
    ADD CONSTRAINT cashbox_pkey PRIMARY KEY (cashbox_id);


--
-- TOC entry 3027 (class 2606 OID 21658)
-- Name: cashbox_transaction_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY cashbox_transaction
    ADD CONSTRAINT cashbox_transaction_pkey PRIMARY KEY (cashbox_transaction_id);


--
-- TOC entry 3029 (class 2606 OID 21660)
-- Name: char_of_account_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY chart_of_accounts
    ADD CONSTRAINT char_of_account_pkey PRIMARY KEY (chart_of_account_id);


--
-- TOC entry 3031 (class 2606 OID 21662)
-- Name: client_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY clients
    ADD CONSTRAINT client_pkey PRIMARY KEY (user_id);


--
-- TOC entry 3037 (class 2606 OID 21664)
-- Name: company_account_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY company_account
    ADD CONSTRAINT company_account_pkey PRIMARY KEY (company_account_id);


--
-- TOC entry 3039 (class 2606 OID 21666)
-- Name: company_employee_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY company_employee
    ADD CONSTRAINT company_employee_pkey PRIMARY KEY (company_employee_id);


--
-- TOC entry 3035 (class 2606 OID 21668)
-- Name: company_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY companies
    ADD CONSTRAINT company_pkey PRIMARY KEY (company_id);


--
-- TOC entry 3210 (class 2606 OID 34863)
-- Name: consume_other_stocks_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY consume_other_stocks_list
    ADD CONSTRAINT consume_other_stocks_list_pkey PRIMARY KEY (consume_other_stocks_list_id);


--
-- TOC entry 3208 (class 2606 OID 34858)
-- Name: consume_other_stocks_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY consume_other_stocks
    ADD CONSTRAINT consume_other_stocks_pkey PRIMARY KEY (consume_other_stocks_id);


--
-- TOC entry 3041 (class 2606 OID 21670)
-- Name: consume_product_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY consume_product_list
    ADD CONSTRAINT consume_product_list_pkey PRIMARY KEY (consume_product_list_id);


--
-- TOC entry 3049 (class 2606 OID 21672)
-- Name: consume_product_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY consume_products
    ADD CONSTRAINT consume_product_pkey PRIMARY KEY (consume_product_id);


--
-- TOC entry 3055 (class 2606 OID 21674)
-- Name: consume_raw_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY consume_raw_list
    ADD CONSTRAINT consume_raw_list_pkey PRIMARY KEY (consume_raw_list_id);


--
-- TOC entry 3057 (class 2606 OID 21676)
-- Name: consume_raw_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY consume_raws
    ADD CONSTRAINT consume_raw_pkey PRIMARY KEY (consume_raw_id);


--
-- TOC entry 3059 (class 2606 OID 21678)
-- Name: creditor_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY creditors
    ADD CONSTRAINT creditor_pkey PRIMARY KEY (creditor_id);


--
-- TOC entry 3015 (class 2606 OID 21680)
-- Name: currency_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY currencies
    ADD CONSTRAINT currency_pkey PRIMARY KEY (currency_id);


--
-- TOC entry 3061 (class 2606 OID 21682)
-- Name: division_account_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY division_account
    ADD CONSTRAINT division_account_pkey PRIMARY KEY (division_account_id);


--
-- TOC entry 3065 (class 2606 OID 21684)
-- Name: division_employee_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY division_employee
    ADD CONSTRAINT division_employee_pkey PRIMARY KEY (division_employee_id);


--
-- TOC entry 3063 (class 2606 OID 21686)
-- Name: division_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY divisions
    ADD CONSTRAINT division_pkey PRIMARY KEY (division_id);


--
-- TOC entry 3051 (class 2606 OID 21688)
-- Name: employee_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY employees
    ADD CONSTRAINT employee_pkey PRIMARY KEY (user_id);


--
-- TOC entry 3067 (class 2606 OID 21690)
-- Name: employee_product_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY employee_product
    ADD CONSTRAINT employee_product_pkey PRIMARY KEY (employee_product_id);


--
-- TOC entry 3072 (class 2606 OID 21692)
-- Name: entry_operation_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY entry_operation
    ADD CONSTRAINT entry_operation_pkey PRIMARY KEY (entry_operation_id);


--
-- TOC entry 3070 (class 2606 OID 21694)
-- Name: entry_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY entries
    ADD CONSTRAINT entry_pkey PRIMARY KEY (entry_id);


--
-- TOC entry 3076 (class 2606 OID 21696)
-- Name: entry_routing_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY entry_routing
    ADD CONSTRAINT entry_routing_pkey PRIMARY KEY (entry_routing_id);


--
-- TOC entry 3074 (class 2606 OID 21698)
-- Name: entry_subaccount_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY entry_subaccount
    ADD CONSTRAINT entry_subaccount_pkey PRIMARY KEY (entry_subaccount_id);


--
-- TOC entry 3078 (class 2606 OID 21700)
-- Name: financial_report_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY financial_report
    ADD CONSTRAINT financial_report_pkey PRIMARY KEY (financial_report_id);


--
-- TOC entry 3082 (class 2606 OID 21702)
-- Name: fixed_assets_details_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY fixed_assets_details
    ADD CONSTRAINT fixed_assets_details_pkey PRIMARY KEY (fixed_assets_details_id);


--
-- TOC entry 3084 (class 2606 OID 21704)
-- Name: fixed_assets_operations_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY fixed_assets_operations
    ADD CONSTRAINT fixed_assets_operations_pkey PRIMARY KEY (fixed_assets_operation_id);


--
-- TOC entry 3080 (class 2606 OID 21706)
-- Name: fixed_assets_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY fixed_assets
    ADD CONSTRAINT fixed_assets_pkey PRIMARY KEY (fixed_assets_id);


--
-- TOC entry 3086 (class 2606 OID 21708)
-- Name: fixed_assets_specification_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY fixed_assets_specification
    ADD CONSTRAINT fixed_assets_specification_pkey PRIMARY KEY (fixed_assets_specification_id);


--
-- TOC entry 3090 (class 2606 OID 21710)
-- Name: inventorization_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY inventorization_list
    ADD CONSTRAINT inventorization_list_pkey PRIMARY KEY (inventorization_list_id);


--
-- TOC entry 3092 (class 2606 OID 21712)
-- Name: inventorization_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY inventorizations
    ADD CONSTRAINT inventorization_pkey PRIMARY KEY (inventorization_id);


--
-- TOC entry 3094 (class 2606 OID 21714)
-- Name: inventory_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY inventory
    ADD CONSTRAINT inventory_pkey PRIMARY KEY (inventory_id);


--
-- TOC entry 3096 (class 2606 OID 21716)
-- Name: inventroy_history_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY inventory_history
    ADD CONSTRAINT inventroy_history_pkey PRIMARY KEY (inventory_history_id);


--
-- TOC entry 3098 (class 2606 OID 21718)
-- Name: jobprice_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY jobprice
    ADD CONSTRAINT jobprice_pkey PRIMARY KEY (jobprice_id);


--
-- TOC entry 3100 (class 2606 OID 21720)
-- Name: jobsheet_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY jobsheet
    ADD CONSTRAINT jobsheet_pkey PRIMARY KEY (jobsheet_id);


--
-- TOC entry 3214 (class 2606 OID 34873)
-- Name: low_value_stock_history_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY low_value_stock_history
    ADD CONSTRAINT low_value_stock_history_pkey PRIMARY KEY (low_value_stock_id);


--
-- TOC entry 3212 (class 2606 OID 34868)
-- Name: low_value_stocks_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY low_value_stock
    ADD CONSTRAINT low_value_stocks_pkey PRIMARY KEY (low_value_stock_id);


--
-- TOC entry 3043 (class 2606 OID 21722)
-- Name: measure_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY measures
    ADD CONSTRAINT measure_pkey PRIMARY KEY (measure_id);


--
-- TOC entry 2983 (class 2606 OID 21724)
-- Name: menu_item_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY access_items
    ADD CONSTRAINT menu_item_pkey PRIMARY KEY (access_item_id);


--
-- TOC entry 3102 (class 2606 OID 21726)
-- Name: net_cost_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY net_cost
    ADD CONSTRAINT net_cost_pkey PRIMARY KEY (net_cost_id);


--
-- TOC entry 3104 (class 2606 OID 21728)
-- Name: order_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY order_list
    ADD CONSTRAINT order_list_pkey PRIMARY KEY (order_list_id);


--
-- TOC entry 3112 (class 2606 OID 21730)
-- Name: order_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY orders
    ADD CONSTRAINT order_pkey PRIMARY KEY (order_id);


--
-- TOC entry 3106 (class 2606 OID 21732)
-- Name: order_raw_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY order_raw_list
    ADD CONSTRAINT order_raw_list_pkey PRIMARY KEY (order_raw_list_id);


--
-- TOC entry 3108 (class 2606 OID 21734)
-- Name: order_raw_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY order_raws
    ADD CONSTRAINT order_raw_pkey PRIMARY KEY (order_raw_id);


--
-- TOC entry 3216 (class 2606 OID 34878)
-- Name: other_stocks_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY other_stocks
    ADD CONSTRAINT other_stocks_pkey PRIMARY KEY (other_stocks_id);


--
-- TOC entry 3224 (class 2606 OID 52492)
-- Name: other_stocks_type_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY other_stocks_type
    ADD CONSTRAINT other_stocks_type_pkey PRIMARY KEY (other_stocks_type_id);


--
-- TOC entry 3114 (class 2606 OID 21736)
-- Name: payment_employee_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY payment_employee
    ADD CONSTRAINT payment_employee_pkey PRIMARY KEY (payment_employee_id);


--
-- TOC entry 3116 (class 2606 OID 21738)
-- Name: payment_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY payments
    ADD CONSTRAINT payment_pkey PRIMARY KEY (payment_id);


--
-- TOC entry 3118 (class 2606 OID 21740)
-- Name: payslip_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY payslips
    ADD CONSTRAINT payslip_pkey PRIMARY KEY (payslip_id);


--
-- TOC entry 3120 (class 2606 OID 21742)
-- Name: percent_rate_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY percent_rate
    ADD CONSTRAINT percent_rate_pkey PRIMARY KEY (percent_rate_id);


--
-- TOC entry 3122 (class 2606 OID 21744)
-- Name: photo_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY photos
    ADD CONSTRAINT photo_pkey PRIMARY KEY (photo_id);


--
-- TOC entry 3053 (class 2606 OID 21746)
-- Name: position_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY positions
    ADD CONSTRAINT position_pkey PRIMARY KEY (position_id);


--
-- TOC entry 3088 (class 2606 OID 21748)
-- Name: posting_fixed_assets_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY posting_fixed_assets
    ADD CONSTRAINT posting_fixed_assets_pkey PRIMARY KEY (posting_fixed_assets_id);


--
-- TOC entry 3124 (class 2606 OID 21750)
-- Name: price_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY prices
    ADD CONSTRAINT price_pkey PRIMARY KEY (price_id);


--
-- TOC entry 3126 (class 2606 OID 21752)
-- Name: product_branch_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY product_branch
    ADD CONSTRAINT product_branch_pkey PRIMARY KEY (product_branch_id);


--
-- TOC entry 3045 (class 2606 OID 21754)
-- Name: product_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY products
    ADD CONSTRAINT product_pkey PRIMARY KEY (product_id);


--
-- TOC entry 3128 (class 2606 OID 21756)
-- Name: product_type_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY product_type
    ADD CONSTRAINT product_type_pkey PRIMARY KEY (product_type_id);


--
-- TOC entry 3132 (class 2606 OID 21758)
-- Name: production_consume_raw_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY production_consume_raw_list
    ADD CONSTRAINT production_consume_raw_list_pkey PRIMARY KEY (consume_raw_list_id);


--
-- TOC entry 3134 (class 2606 OID 21760)
-- Name: production_consume_raw_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY production_consume_raws
    ADD CONSTRAINT production_consume_raw_pkey PRIMARY KEY (consume_raw_id);


--
-- TOC entry 3136 (class 2606 OID 21762)
-- Name: production_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY production_list
    ADD CONSTRAINT production_list_pkey PRIMARY KEY (production_list_id);


--
-- TOC entry 3130 (class 2606 OID 21766)
-- Name: production_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY production
    ADD CONSTRAINT production_pkey PRIMARY KEY (production_id);


--
-- TOC entry 3140 (class 2606 OID 21768)
-- Name: production_plan_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY production_plan_list
    ADD CONSTRAINT production_plan_list_pkey PRIMARY KEY (production_plan_list_id);


--
-- TOC entry 3138 (class 2606 OID 21770)
-- Name: production_plan_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY production_plan
    ADD CONSTRAINT production_plan_pkey PRIMARY KEY (production_plan_id);


--
-- TOC entry 3110 (class 2606 OID 21774)
-- Name: purveyor_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY purveyors
    ADD CONSTRAINT purveyor_pkey PRIMARY KEY (user_id);


--
-- TOC entry 3218 (class 2606 OID 34883)
-- Name: receipt_other_stocks_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY receipt_other_stocks_list
    ADD CONSTRAINT receipt_other_stocks_list_pkey PRIMARY KEY (receipt_other_stocks_list_id);


--
-- TOC entry 3220 (class 2606 OID 34888)
-- Name: receipt_other_stocks_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY receipt_other_stocks
    ADD CONSTRAINT receipt_other_stocks_pkey PRIMARY KEY (receipt_other_stocks_id);


--
-- TOC entry 3144 (class 2606 OID 21776)
-- Name: receipt_product_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY receipt_product_list
    ADD CONSTRAINT receipt_product_list_pkey PRIMARY KEY (receipt_product_list_id);


--
-- TOC entry 3146 (class 2606 OID 21778)
-- Name: receipt_product_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY receipt_products
    ADD CONSTRAINT receipt_product_pkey PRIMARY KEY (receipt_product_id);


--
-- TOC entry 3148 (class 2606 OID 21780)
-- Name: refund_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY refunds
    ADD CONSTRAINT refund_pkey PRIMARY KEY (refund_id);


--
-- TOC entry 3033 (class 2606 OID 21783)
-- Name: region_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY locations
    ADD CONSTRAINT region_pkey PRIMARY KEY (location_id);


--
-- TOC entry 3150 (class 2606 OID 21785)
-- Name: relarion_type_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY relation_type
    ADD CONSTRAINT relarion_type_pkey PRIMARY KEY (relation_type_id);


--
-- TOC entry 3152 (class 2606 OID 21787)
-- Name: relation_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY relations
    ADD CONSTRAINT relation_pkey PRIMARY KEY (relation_id);


--
-- TOC entry 3154 (class 2606 OID 21789)
-- Name: return_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY return_list
    ADD CONSTRAINT return_list_pkey PRIMARY KEY (return_list_id);


--
-- TOC entry 3156 (class 2606 OID 21791)
-- Name: return_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY returns
    ADD CONSTRAINT return_pkey PRIMARY KEY (return_id);


--
-- TOC entry 2987 (class 2606 OID 21793)
-- Name: role_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY roles
    ADD CONSTRAINT role_pkey PRIMARY KEY (role_id);


--
-- TOC entry 3158 (class 2606 OID 21795)
-- Name: salary_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY salaries
    ADD CONSTRAINT salary_pkey PRIMARY KEY (salary_id);


--
-- TOC entry 3160 (class 2606 OID 21797)
-- Name: salary_type_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY salary_type
    ADD CONSTRAINT salary_type_pkey PRIMARY KEY (salary_type_id);


--
-- TOC entry 3162 (class 2606 OID 21799)
-- Name: shareholder_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY shareholders
    ADD CONSTRAINT shareholder_pkey PRIMARY KEY (user_id);


--
-- TOC entry 3164 (class 2606 OID 21801)
-- Name: specification_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY specification_list
    ADD CONSTRAINT specification_list_pkey PRIMARY KEY (specification_list_id);


--
-- TOC entry 3166 (class 2606 OID 21803)
-- Name: specification_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY specifications
    ADD CONSTRAINT specification_pkey PRIMARY KEY (specification_id);


--
-- TOC entry 3170 (class 2606 OID 21805)
-- Name: spoilage_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY spoilage_list
    ADD CONSTRAINT spoilage_list_pkey PRIMARY KEY (spoilage_list_id);


--
-- TOC entry 3168 (class 2606 OID 21807)
-- Name: spoilage_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY spoilage
    ADD CONSTRAINT spoilage_pkey PRIMARY KEY (spoilage_id);


--
-- TOC entry 3172 (class 2606 OID 21809)
-- Name: state_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY state
    ADD CONSTRAINT state_pkey PRIMARY KEY (state_id);


--
-- TOC entry 3047 (class 2606 OID 21811)
-- Name: status_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY status
    ADD CONSTRAINT status_pkey PRIMARY KEY (status_id);


--
-- TOC entry 3174 (class 2606 OID 21813)
-- Name: status_rule_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY status_rule
    ADD CONSTRAINT status_rule_pkey PRIMARY KEY (status_rule_id);


--
-- TOC entry 3178 (class 2606 OID 21815)
-- Name: stock_history_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY stock_history
    ADD CONSTRAINT stock_history_pkey PRIMARY KEY (stock_id);


--
-- TOC entry 3176 (class 2606 OID 21817)
-- Name: stock_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY stock
    ADD CONSTRAINT stock_pkey PRIMARY KEY (stock_id);


--
-- TOC entry 3180 (class 2606 OID 21819)
-- Name: stock_transfer_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY stock_transfer_list
    ADD CONSTRAINT stock_transfer_list_pkey PRIMARY KEY (stock_transfer_list_id);


--
-- TOC entry 3182 (class 2606 OID 21821)
-- Name: stock_transfers_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY stock_transfers
    ADD CONSTRAINT stock_transfers_pkey PRIMARY KEY (stock_transfer_id);


--
-- TOC entry 3184 (class 2606 OID 21823)
-- Name: subaccount_history_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY subaccount_history
    ADD CONSTRAINT subaccount_history_pkey PRIMARY KEY (subaccount_history_id);


--
-- TOC entry 3017 (class 2606 OID 21825)
-- Name: subaccount_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY subaccounts
    ADD CONSTRAINT subaccount_pkey PRIMARY KEY (subaccount_id);


--
-- TOC entry 3186 (class 2606 OID 21827)
-- Name: tax_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY taxes
    ADD CONSTRAINT tax_pkey PRIMARY KEY (tax_id);


--
-- TOC entry 3188 (class 2606 OID 21829)
-- Name: timesheet_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY timesheet
    ADD CONSTRAINT timesheet_pkey PRIMARY KEY (timesheet_id);


--
-- TOC entry 3222 (class 2606 OID 52483)
-- Name: transport_history_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY transport_history
    ADD CONSTRAINT transport_history_pkey PRIMARY KEY (transport_history_id);


--
-- TOC entry 3190 (class 2606 OID 21831)
-- Name: transport_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY transport_list
    ADD CONSTRAINT transport_list_pkey PRIMARY KEY (transport_list_id);


--
-- TOC entry 3192 (class 2606 OID 21836)
-- Name: transport_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY transports
    ADD CONSTRAINT transport_pkey PRIMARY KEY (transport_id);


--
-- TOC entry 2997 (class 2606 OID 21838)
-- Name: user_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY users
    ADD CONSTRAINT user_pkey PRIMARY KEY (user_id);


--
-- TOC entry 3194 (class 2606 OID 21840)
-- Name: warehouse_employee_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY warehouse_employee
    ADD CONSTRAINT warehouse_employee_pkey PRIMARY KEY (warehouse_employee_id);


--
-- TOC entry 3142 (class 2606 OID 21842)
-- Name: warehouse_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY warehouse
    ADD CONSTRAINT warehouse_pkey PRIMARY KEY (warehouse_id);


--
-- TOC entry 3196 (class 2606 OID 21844)
-- Name: warehouse_type_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY warehouse_type
    ADD CONSTRAINT warehouse_type_pkey PRIMARY KEY (warehouse_type_id);


--
-- TOC entry 3204 (class 2606 OID 21846)
-- Name: wite_off_raw_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY write_off_raws
    ADD CONSTRAINT wite_off_raw_pkey PRIMARY KEY (write_off_raw_id);


--
-- TOC entry 3198 (class 2606 OID 21849)
-- Name: withdrawal_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY withdrawals
    ADD CONSTRAINT withdrawal_pkey PRIMARY KEY (withdrawal_id);


--
-- TOC entry 3200 (class 2606 OID 21851)
-- Name: write_off_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY write_off_list
    ADD CONSTRAINT write_off_list_pkey PRIMARY KEY (write_off_list_id);


--
-- TOC entry 3206 (class 2606 OID 21853)
-- Name: write_off_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY write_offs
    ADD CONSTRAINT write_off_pkey PRIMARY KEY (write_off_id);


--
-- TOC entry 3202 (class 2606 OID 21855)
-- Name: write_off_raw_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY write_off_raw_list
    ADD CONSTRAINT write_off_raw_list_pkey PRIMARY KEY (write_off_raw_list_id);


--
-- TOC entry 3068 (class 1259 OID 21856)
-- Name: entry_date_index; Type: INDEX; Schema: OrmasSchema; Owner: postgres
--

CREATE INDEX entry_date_index ON "OrmasSchema".entries USING btree (entry_date DESC);


--
-- TOC entry 3225 (class 2606 OID 21857)
-- Name: access_fkey; Type: FK CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY accesses
    ADD CONSTRAINT access_fkey FOREIGN KEY (access_item_id) REFERENCES access_items(access_item_id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 3226 (class 2606 OID 21862)
-- Name: balance_subaccount_fkey; Type: FK CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY balances
    ADD CONSTRAINT balance_subaccount_fkey FOREIGN KEY (subaccount_id) REFERENCES subaccounts(subaccount_id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 3227 (class 2606 OID 21867)
-- Name: balance_user_fkey; Type: FK CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY balances
    ADD CONSTRAINT balance_user_fkey FOREIGN KEY (user_id) REFERENCES users(user_id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 3228 (class 2606 OID 21872)
-- Name: client_fkey; Type: FK CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY clients
    ADD CONSTRAINT client_fkey FOREIGN KEY (user_id) REFERENCES users(user_id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 3229 (class 2606 OID 21877)
-- Name: employee_fkey; Type: FK CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY employees
    ADD CONSTRAINT employee_fkey FOREIGN KEY (user_id) REFERENCES users(user_id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 3230 (class 2606 OID 21882)
-- Name: purveyor_fkey; Type: FK CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY purveyors
    ADD CONSTRAINT purveyor_fkey FOREIGN KEY (user_id) REFERENCES users(user_id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 3231 (class 2606 OID 21887)
-- Name: salary_fkey; Type: FK CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY salaries
    ADD CONSTRAINT salary_fkey FOREIGN KEY (user_id) REFERENCES users(user_id);


--
-- TOC entry 3479 (class 0 OID 0)
-- Dependencies: 7
-- Name: OrmasSchema; Type: ACL; Schema: -; Owner: postgres
--

REVOKE ALL ON SCHEMA "OrmasSchema" FROM PUBLIC;
REVOKE ALL ON SCHEMA "OrmasSchema" FROM postgres;
GRANT ALL ON SCHEMA "OrmasSchema" TO postgres;
GRANT ALL ON SCHEMA "OrmasSchema" TO PUBLIC;


--
-- TOC entry 3481 (class 0 OID 0)
-- Dependencies: 8
-- Name: public; Type: ACL; Schema: -; Owner: postgres
--

REVOKE ALL ON SCHEMA public FROM PUBLIC;
REVOKE ALL ON SCHEMA public FROM postgres;
GRANT ALL ON SCHEMA public TO postgres;
GRANT ALL ON SCHEMA public TO PUBLIC;


-- Completed on 2020-05-02 14:04:56

--
-- PostgreSQL database dump complete
--

