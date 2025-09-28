CREATE DATABASE SimpleClinicDB;

USE SimpleClinicDB;

CREATE TABLE Persons
(
	person_id INT IDENTITY(1,1) PRIMARY KEY,
	full_name NVARCHAR(100) NOT NULL,
	birthdate DATE NOT NULL,
	gender CHAR(1) NOT NULL,
	phone_number VARCHAR(15) NOT NULL,
	email VARCHAR(50) NOT NULL UNIQUE,
	[address] NVARCHAR(255) NOT NULL,
);

CREATE TABLE Patients
(
	patient_id INT IDENTITY(1,1) PRIMARY KEY,
	person_id INT REFERENCES Persons(person_id)
);

CREATE TABLE Doctors
(
	doctor_id INT IDENTITY(1,1) PRIMARY KEY,
	person_id INT REFERENCES Persons(person_id),
	specialization NVARCHAR(100) NOT NULL
);

CREATE TABLE Appointments
(
	appointment_id INT IDENTITY(1,1) PRIMARY KEY,
	patient_id INT REFERENCES Patients(patient_id),
	doctor_id INT REFERENCES Doctors(doctor_id),
	appointment_datetime DATETIME NOT NULL,
	appointment_status TINYINT NOT NULL,
);

CREATE TABLE MedicalRecords
(
	record_id INT IDENTITY(1,1) PRIMARY KEY,
	appointment_id INT REFERENCES Appointments(appointment_id),
	description_of_visit NVARCHAR(MAX),
	dignosis NVARCHAR(255),
	additional_notes NVARCHAR(MAX)
);

CREATE TABLE Prescriptions
(
	prescription_id INT IDENTITY(1,1) PRIMARY KEY,
	medical_record_id INT REFERENCES MedicalRecords(record_id),
	medication_name NVARCHAR(255) NOT NULL,
	dosage NVARCHAR(100) NOT NULL,
	frequency NVARCHAR(50) NOT NULL,
	[start_date] DATE NOT NULL,
	[end_date] DATE NOT NULL,
	special_instructions NVARCHAR(255) NOT NULL
);

CREATE TABLE Payments
(
	payment_id INT IDENTITY(1,1) PRIMARY KEY,
	appointment_id INT REFERENCES Appointments(appointment_id),
	payment_date DATETIME,
	payment_method NVARCHAR(255),
	amount_paid MONEY,
	additonal_notes NVARCHAR(255)
);